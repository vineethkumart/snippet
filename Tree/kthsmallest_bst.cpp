// Nothing but kth node in inorder traversal
// reverse the order and you will get kth max element

int ksm(Node* root, int i, int k)
{
    if (!root) return -1;
    int ans = ksm(root->left, i, k);
    if (ans != -1) return ans;
    if (i == k) return root;
    i++;
    return ksm(root->right, i, k);
}
