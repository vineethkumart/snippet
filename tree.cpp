
// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>
#include <cassert>

using namespace std;

template<typename data_t>
struct NodeT {
	data_t data;
	NodeT* left;
	NodeT* right;

	data_t& operator*() { return data; }

	NodeT(int d) : data(d), left(0), right(0) {}
};

using Node = NodeT<int>;

static constexpr auto NC = 99; 

// build a tree rooting at a[idx] and return back
Node* build_tree(int *a, int n, int i)
{
	if (i >= n) return nullptr;
	if (a[i] == NC) return nullptr;
	Node* root = new Node(a[i]);
	root->left = build_tree(a, n, 2*i+1);
	root->right = build_tree(a, n, 2*i+2);
	return root;
}

void convert_back(Node* root, int i, int* a, int size) 
{
	if (i >= size) return; // shouldn't happen
	if (root == nullptr) {
		a[i] = NC;
		return;
	}
	
	a[i] = **root;
	convert_back(root->left, 2*i+1, a, size);
	convert_back(root->right, 2*i+2, a, size);
}

void print_tree(Node* root) 
{
	if (root == nullptr){ return;}
	cout << root->data << " ";
	print_tree(root->left);
	print_tree(root->right);
}

int main()
{
	// tree is given in an array, i
	int a[] = {1,2,3,4,5,6,7,8,9,10,11,NC,13,NC,15};
	constexpr auto n = sizeof(a)/ sizeof(a[0]);
	
	// recursively build the tree, create root
	if (a[0] == NC || n == 0) return 0;
	Node* root = new Node(a[0]);
	root->left = build_tree(a, n, 1);
	root->right = build_tree(a, n, 2);

	print_tree(root);

	// Convert the tree back to an array representation
	int b[n];
	convert_back(root, 0, b, n);

	// assert same
	for (int i = 0; i < n; i++) {
		assert(a[i] == b[i]);
	}
	return 0;
} 
