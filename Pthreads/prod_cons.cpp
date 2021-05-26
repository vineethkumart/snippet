#include <pthread.h>
#include <cstdio>
#include <cstdint>
#include <cassert>
#include <unistd.h>

static const int SIZE = 5;
volatile static uint16_t N(0);
volatile static bool done(false);
volatile static int counter(0);
static volatile int arr[SIZE];
pthread_mutex_t lock(PTHREAD_MUTEX_INITIALIZER);
pthread_cond_t empty(PTHREAD_COND_INITIALIZER);
pthread_cond_t full(PTHREAD_COND_INITIALIZER);

void* producer(void* arg)
{
    uint8_t tid = *(uint8_t*)arg;

    while (true) {
        pthread_mutex_lock(&lock);
        while (N == SIZE && !done)
            pthread_cond_wait(&full, &lock);

        if (done) {
            pthread_mutex_unlock(&lock);
            return 0;
        }

        // produce
        arr[N++] = counter;
        printf("tid: %hhu, produced %hu\n", tid, counter++);
        pthread_cond_broadcast(&empty);
        pthread_mutex_unlock(&lock);
    }
}


void* consumer(void* arg)
{
    uint8_t tid = *(uint8_t*)arg;
    while (true) {
        pthread_mutex_lock(&lock);
        while (N == 0 && !done)
            pthread_cond_wait(&empty, &lock);

        assert(N >= 0);
        // consume
        if (done && N == 0) {
            pthread_mutex_unlock(&lock);
            return 0;
        }

        printf("tid: %hhu, consumed %hu\n", tid, arr[N--]);
        pthread_cond_broadcast(&full);
        pthread_mutex_unlock(&lock);

        // consume
        sleep(1);
    }
}


int main()
{
    pthread_t tid[10]; // 3 producers and 7 consumers, production fast and consumption is slow

    for (int i = 0; i < 3; i++) {
        int rc = pthread_create(&tid[i], NULL, producer, (void*)&i);
        assert(rc == 0);
    }

    for (int i = 3; i < 10; i++) {
        int rc = pthread_create(&tid[i], NULL, consumer, (void*)&i);
        assert(rc == 0);
    }

    sleep(10);
    printf("ending..\n");
    done = true;

    for (int i = 0; i < 10; i++) {
        pthread_join(tid[i], NULL);
        printf("tid %hhu joined\n", i);
    }

    return 0;
}
