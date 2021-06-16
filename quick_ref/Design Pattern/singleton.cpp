class Singleton {
public:
    static Singleton& Instance() {
        static Singleton s(args...);
        return s;
    }
private:
    Singleton(args...) {};
    
    Singleton(const Singleton&) = delete;
    Singleton & operator=(const Singleton&) = delete;
};