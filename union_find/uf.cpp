class uf_t {
public:
    uf_t(int V) {
        for (int i = 0; i < V; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int i) {
        if (i == parent[i]) return i;
        int r = find(parent[i]);
        parent[i] = r; // this is important for path compression
        return r;
    }

    void un(int i, int j)
    {
        int a = find(i); // this is important for correctness
        int b = find(j);

        if (rank[a] <= rank[b]) {
            parent[a] = b;
            rank[a]++; // this is important for logrithmic bound   1->2 and 3 then should be 1->(2,3) with height remaining at 2 not 3->1->2 h increase
        } else {
            parent[b] = a;
        }
    }
private:
    vector<int> parent;
    vector<int> rank;
};

int main()
{

}
