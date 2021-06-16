#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

class Trie {
private:
struct Node {
        Node() {
            leaf = false;
            memset(c, 0, sizeof(c));
        }

        Node* c[256];
        bool leaf;
    };

public:
    Trie() { root = new Node();}

    void insert(string word) {
        Node* n = root;
        for (auto i : word) {
            if (!n->c[i]) {
                n->c[i] = new Node();
            }

            n = n->c[i];
        }
        n->leaf = true;
    }

    bool search(string word) {
        Node* n = root;
        for (auto i : word) {
            if (!n->c[i]) return false;
            n = n->c[i];
        }

        return n->leaf;
    }

    bool prefix(string word) {
        Node* n = root;
        for (auto i : word) {
            if (!n->c[i]) return false;
            n = n->c[i];
        }
        return true;
    }

    void printall(Node* n, vector<string>& v, string& w)
    {
        assert(n);
        if (n->leaf) {
            // push to v
            v.push_back(w);
        }

        for(int i = 0; i < 256; i++) {
            if (n->c[i]) {
                w.push_back((char)i);
                printall(n->c[i], v, w);
                w.pop_back();
            }
        }
    }

    vector<string> findall(string prefix) {
        Node* n = root;
        for (auto i : prefix) {
            if (!n->c[i]) return {};
            n = n->c[i];
        }

        // print all startgin from n
        vector<string> v;
        string w;
        printall(n, v, w);

        return v;
    }

private:
    
    Node* root;
};

int main()
{
    Trie t;
    t.insert("vineeth");
    t.insert("vinod");
    t.insert("v");
    t.insert("va");
    t.insert("vav");
    cout <<t.search("vineeth");
    cout <<t.prefix("vin");
    cout <<t.search("vin");
    cout << t.search("vinod");
    vector<string> v;
    v = t.findall("v");
    for (auto i : v) {
        cout << "v" + i << endl;
    }

}
