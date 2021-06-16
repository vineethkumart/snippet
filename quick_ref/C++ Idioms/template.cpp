template<int n>
class fact {
    static const int val = n * fact<n-1>;
};

template<>
class fact<1> { static const int val = 1; };

int main() {
    fact<5>::val;
}

constexpr int fact(int n) { if (n == 1) return 1; return n * fact(n-1);}


