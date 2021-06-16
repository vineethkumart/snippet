struct tdata_t
{
    tdata_t(int i, ThreadPool<int>* tp) : id(i), tp(tp) {}
    int id;
    ThreadPool<int>* tp;
};

void* thread_body(void* args)
{
    tdata_t* td = static_cast<tdata_t*>(args);
    td->tp->Body(td->id)
}


template<typename T, int SIZE>
class ThreadPool {
public:
    ThreadPool() {}

    void CreatePool() {
        for (int i = 0; i < SIZE; i++) {
            tdata_t* data = new tdata_t(i, this);
            int status = pthread_create(&threads[i], NULL, thread_body, reinterpret_cast<void*>(data);
            assert(status != 0);
        }
    }
    void JoinPool() {
        for (int i = 0; i < SIZE; i++) {
            pthread_join(threads[i], 0);
        }
    }

    void Body(int id) {
        // thread body;
        while (true) {
            pthread_mutex_lock(&lock);
            while (..)
        }

    };
private:
    pthread_t threads[SIZE];
    queue<T> items;
};