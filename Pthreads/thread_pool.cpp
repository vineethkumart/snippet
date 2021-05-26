#include <pthread.h>
#include <queue>
#include <cstdint>
#include <cassert>
#include <cstdio>
#include <unistd.h>


using namespace std;

class ThreadPool;

class Request_t 
{
public:
    Request_t(uint8_t i) : id(i) {}
    void process(uint8_t tid) {
        sleep(1);
        printf("Thread %hhu processing %hhu\n", tid, id);

    }

    uint8_t id;
};

class ThreadData
{
    friend class ThreadPool;

public:
    ThreadData() : id(0),mgr(0) {}
    ThreadData(uint8_t _id, ThreadPool* tp) {
        id = _id;
        mgr = tp;
    }
    ThreadPool* tmgr() { return mgr; }

private:
    uint8_t id;
    ThreadPool* mgr;
    // any thread specific data
};

void* c_thread_body(void* arg);
class ThreadPool
{
public:
    ThreadPool(uint8_t num) : num_th(num), lock(PTHREAD_MUTEX_INITIALIZER), cv(PTHREAD_COND_INITIALIZER), tdata(0), tids(0), finished(0) {}
    ~ThreadPool()
    {
        // wait for threads to join
        for (uint8_t i = 0; i < num_th; i++) {
            pthread_join(tids[i], nullptr);
        }

        delete[] tdata;
        delete[] tids;
    }

    void CreateThreads()
    {
        assert(num_th >= 0);
        assert(!tdata);
        tdata = new ThreadData[num_th];
        tids = new pthread_t[num_th];
        for (uint8_t i = 0; i < num_th; i++) {
            ThreadData* td = new(&tdata[i]) ThreadData(i, this);
            int ret = pthread_create(&tids[i], NULL/*attr*/, c_thread_body, static_cast<void*>(td));
            assert(!ret);
        }
    }

    void AddJob(Request_t req)
    {
        printf("Adding Job %hhu\n", req.id);
        pthread_mutex_lock(&lock);
        q.push(req);
        pthread_cond_broadcast(&cv);
        pthread_mutex_unlock(&lock);
    }

    void Finish()
    {
        finished = true;
        pthread_mutex_lock(&lock);
        pthread_cond_broadcast(&cv);
        pthread_mutex_unlock(&lock);
    }


    int ThreadBody(ThreadData* td)
    {
        while (true) 
        {
            pthread_mutex_lock(&lock);
            while (q.empty() && !finished)
                pthread_cond_wait(&cv, &lock);

            if (finished && q.empty()) {
                pthread_mutex_unlock(&lock);
                return 0;
            }

            Request_t r = q.front(); q.pop();
            pthread_mutex_unlock(&lock);

            r.process(td->id);
        }
    }

private:
    uint8_t num_th;
    pthread_mutex_t lock;
    pthread_cond_t  cv;
    ThreadData* tdata;
    pthread_t* tids;
    volatile uint8_t finished;
    queue<Request_t> q;
};

void* c_thread_body(void* arg)
{
    ThreadData* td = static_cast<ThreadData*>(arg);
    td->tmgr()->ThreadBody(td);
    return nullptr;
}

int main()
{
    int NUM_TH = 4;
    ThreadPool tp(NUM_TH);

    tp.CreateThreads();

    for (int i = 10; i <= 50; i++) {
        Request_t r(i);
        tp.AddJob(r);
    }

    tp.Finish();

    return 0;
}
