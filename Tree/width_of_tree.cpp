/**
 * Structural max width of a binary tree
 * };
 */
class Solution {
    public:
        using Node = TreeNode;
        int widthOfBinaryTree(TreeNode* root) {

            typedef struct {
                Node* root;
                unsigned long long i;
            } el_t;
            queue<el_t> q;
            q.push({root, 0});;

            unsigned long long ans = 0;
            while (!q.empty()) {
                auto size = q.size();
                assert(size);
                unsigned long long s = q.front().i;
                for (int i = 0; i < size; i++) {
                    auto e = q.front();q.pop();
                    cout << e.i << endl;
                    ans = max(ans, e.i - s + 1);
                    if (e.root->left)
                        q.push({e.root->left, 2*e.i+1});
                    if (e.root->right)
                        q.push({e.root->right, 2*e.i+2});
                }
            }

            return ans;
        }
};
