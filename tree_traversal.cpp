// Tree traversals
void inorder(Node* root)
{
	if (!root) return;
	inorder(root->left);
	cout << **root << " ";
	inorder(root->right);
}

void preorder(Node* root)
{
	if (!root) return;
	cout << **root << " ";
	preorder(root->left);
	preorder(root->right);
}

void postorder(Node* root)
{
	if (!root) return;
	postorder(root->left);
	postorder(root->right);
	cout << **root << " ";
}

void levelorder(Node* root)
{
	queue<Node*> q;
	q.push(root);
	q.push(nullptr);
	while (!q.empty()) {
		if (q.front() == nullptr) {q.pop(); if(q.empty()) break; q.push(nullptr); continue;}
		cout << q.front()->data << " ";
		if (q.front()->left) q.push(q.front()->left);
		if (q.front()->right) q.push(q.front()->right);
		q.pop();
	}
}