struct nullptr_t 
{
    void operator&() const = delete;

    template<class T>
    inline operator T*() const { return 0; }
    
    template<class C, class T>
    inline operator T C::*() const { return 0; }
};

nullptr_t nullptr;
