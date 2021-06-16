// iterative inoroder
void inorder(Node* root)
{
    vector<int> inOrder(Node* root)
    {
        vector<int> v;
        stack<Node*> s;
        if (!root) return {};
        do {
            while (root) {
                s.push(root);
                root = root->left;
            }

            Node* h = s.top(); s.pop();
            v.push_back(h->data);
            root = h->right;
        } while (root || !s.empty());

        return v;
    }
}

vector <int> preorder(Node* root)
{
    vector<int> a;
    stack<Node*> s;
    s.push(root);

    do {
        root = s.top(); s.pop();
        a.push_back(root->data);
        if (root->right)
            s.push(root->right);
        if (root->left)
            s.push(root->left);
    } while (!s.empty());

    return a;
}


void postorder(Node* root)
{
    stack<Node*> s;
    s.push(root);
    do {
        while (root) {
            root = root->left;
            if (root) s.push(root);
        }
        root = s.top();
        if (root->right == nullptr) {
            cout << root->data << " ";
            s.pop();
        }
        // print to root while backtracking
        while (!s.empty() && root == s.top()->right) {
            root = s.top();
            s.pop();
            cout << root->data << " ";
        }
        
        if (s.empty()) return;
        root = s.top()->right;
        s.push(root);
    } while (!s.empty());
}
