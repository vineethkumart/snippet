template<typename T, int N>
class ProdCons {
public:
    ProdCons() : c(0), lock(PTHREAD_MUTEX_INITIALIZER), c1(PTHREAD_COND_INITIALIZER), c2(PTHREAD_COND_INITIALIZER) {}

    void producer() {
        while (1) {
            T item = Produce();
            pthread_mutex_lock(&lock);
            while (c == N)
                pthread_cond_wait(&c1, &lock);
            items[c++] = item;
            pthread_cond_signal(&c2);
            pthread_mutex_unlock(&lock);
        }
    }

    void consumer() {
        while (1) {
            pthread_mutex_lock(&lock);
            while (c == 0) 
                pthread_cond_wait(&c2, &lock);
            // get item
            T item = items[c--];
            pthread_cond_signal(&c1);
            pthread_mutex_unlock(&lock);
            CONSUME(item);
        }
    }

private:
    volatile T items[N];
    volatile int c;


    pthread_mutex_t lock;
    pthread_cond_t c1;
    pthread_cond_t c2;
};
