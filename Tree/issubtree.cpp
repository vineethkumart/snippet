/* Given 2 trees check if 2nd tree is a subtree of the 1st subtre */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public:
        bool isSame(TreeNode* root, TreeNode* sub) {
            if (!root && !sub) return true;
            if (!root || !sub) return false;
            if (root->val != sub->val) return false;
            return isSame(root->left, sub->left) && isSame(root->right, sub->right);
        }

        bool isSubtree(TreeNode* root, TreeNode* subRoot) {
            if (!root && !subRoot) return true;
            if (!root || !subRoot) return false;

            if (root->val == subRoot->val) {
                // check for a match
                if (isSame(root, subRoot)) return true;
            }

            return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        }
};
