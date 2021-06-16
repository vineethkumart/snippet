

class ino_itr
{
public:
    ino_itr(Node* root) : root(root) {}


    Node* begin() {
        s.flush();
        s.push(root);
        add_successor();
        Node* cur = s.top(); s.pop();
        return cur;
    }

    Node* end() {
        return NULL;
    }

    void add_successor()
    {
        Node* cur = s.top(); s.pop();

        while (cur) {
            if (cur->left) s.push(cur->left); // keep pushing left st
        }

        cur = s.top(); // to be returned
        // push rst if exists
        
        if (cur->right) s.push(cur->right);
        return cur;
    }
    
    // pre increment
    Node* operator++()
    {
        add_successor();
        Node* cur = s.top(); s.pop();
        return cur;
    }

    // post increment
    Node* operator++(int) {
        Node* t = cur;
    }

private:
    Node* root;
    Node* cur;
    stack<Node*> s;
}
