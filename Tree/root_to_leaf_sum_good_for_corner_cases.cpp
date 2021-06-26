// Find a Root to Leaf path with given sum
// Should work for +ve and -ve numbers and target
//


bool find(Node* root, int sum)
{
    if (!root) return false;
    sum -= root->val;
    if (sum == 0 && !root->left && !root->right) return true;

    return (find(root->left, sum) || find(root->right, sum));

}
