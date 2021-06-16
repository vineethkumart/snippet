// busy loop imple
class sem_t{
public:
    sem_t() : count(1) {}
    void P() {
        while (!__sync_bool_compare_and_swap(&count, 1, 0));
    }

    void V() {
        __sync_fetch_and_increment(&count);
    }

private:
    volatile int count;
};


// non blocking impl
class sem_t{
public:
    sem_t() : count(1), cv(PTHREAD_COND_INITIALIZER), lock(PTHREAD_MUTEX_INITIALIZER) {
    }
    void P() {
        pthread_mutex_lock(&lock);
        while (count == 0) 
            pthread_cond_wait(&lock, &cv);

        pthread_mutex_unlock();
        // return and enter CS
    }

    void V() {
        assert(counter == 1);
        pthred_mutex_lock(&lock);
        counter--;
        pthread_cond_signal(&cv);
        pthread_mutex_unlock(&lock);
    }

private:
    volatile int count;
    pthread_cond_t cv;
    pthread_mutex_t lock;
};
