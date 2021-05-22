// iterative inoroder

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


void inorder(Node* root)
{
stack<Node*> s;
s.push(root);
do {
	while (root) {
        root = root->left;
        if (root) s.push(root);
    }
    
    // print top of the stack
    Node* cur = s.top(); s.pop();
    cout << cur->data << " ";

    // push right subtree
    if (cur->right) s.push(cur->right);
    root = cur->right;
} while (!s.empty());
}

void preorder(Node* root)
{
    stack<Node*> s;
    s.push(root);
        do {
            while (root) {
                cout << root->data << " ";
                root = root->left;
                if (root) s.push(root);
            }
            Node* cur = s.top();s.pop();
            root = cur->right;
            if (root) s.push(root);
    } while (!s.empty());
}
