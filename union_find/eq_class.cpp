#include <iostream>
#include <vector>
#include <set>

using namespace std;

class uf_t {
public:
    uf_t(int size) {
        for (int i =0; i < size; i++) {
            set_t s;
            s.parent = i;
            s.rank = 0;
            sets.push_back(s);
        }
    }

    int find_root(int i)
    {
        if (sets[i].parent == i) return i;
        int root = find_root(sets[i].parent);
        sets[i].parent = root; // path compression

        return root;
    }

    int do_union(int i, int j)
    {
        if (sets[i].rank < sets[j].rank) {
            sets[i].parent = j;
        }
        sets[j].parent = i;

        if (sets[i].rank == sets[j].rank) sets[i].rank++;

        auto itr = roots.find(j);
        roots.erase(itr);
        if (roots.find(i) == roots.end()) roots.insert(i);

        return i;
    }

    template<typename lambda>
    void for_each_set(lambda f)
    {
        for (auto i : roots) {
            f(i);
        }
    }
private:
    typedef struct {
        int parent;
        int rank;

        // other attributes to store
    } set_t;

    set<int> roots;
    vector<set_t> sets;
};

bool isrelated(int a, int b)
{
    return (a == b);
}

int main()
{
    int el[] = {1,2,1,2,3,4,5,4,8,8,2,10};
    auto const n = sizeof(el)/ sizeof(el[0]);
    uf_t uf(n);

    // iteratively do union of sets based on the given condition

    int done = true;
    while (!done)
    {
        done = true;
        uf.for_each_set([&](int i) {
            uf.for_each_set([&](int j) {
                if (i != j && isrelated(i, j)) {
                    uf.do_union(i, j);
                    done = false;
                }
            });
        });
    }

    // print the partiton
    for (int i = 0; i < n; i++) {
        cout << i << ": " << uf.find_root(i) << endl;
    }
}
