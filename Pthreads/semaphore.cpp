#include <semaphore.h>
#include <pthread.h>

static const int SIZE = 5;
static volatile int N(0);
static bool volatile done(false);

sem_t full;
sem_t empty;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;


void* producer_body(void* arg)
{
    while (true)
    {
        if (done) return 0;
        sem_wait(&full);
        pthread_mutex_lock(&lock);
        N++;
        pthread_mutex_unlock(&lock);
        sem_post(&empty);
    }
}

void* consumer_body(void* arg)
{
    while (true)
    {
        if (done) return 0;

        sem_wait(&empty);
        pthread_mutex_lock(&lock);
        N--;
        pthread_mutex_unlock(&lock);
        sem_post(&full);
    }
}

int main()
{
    sem_init(&full, 0, SIZE);
    sem_init(&empty, 0, 0);
}
