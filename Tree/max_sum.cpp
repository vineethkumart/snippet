int cv(INT_MIN);
int max_sum(Node* root, int& mx)
{
    if (!root) return 0;

    int fv = max((max(max_sum(root->left), max_sum(root->right)) + root->data), root->data);
    int cv = max(fv, (max_sum(root->left) + max_sum(root->right))+root->data);

    cv = max(cv, mx);

    return fv;
}
