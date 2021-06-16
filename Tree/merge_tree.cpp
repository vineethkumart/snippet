// Given 2 binary trees. merge them into a new tree.
// If there are overlapping nodes, merge with sum of the values, else value of present tree node
//
//https://leetcode.com/problems/merge-two-binary-trees/ 

class Solution {
    public:
        using Node = TreeNode;
        TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
            if (!root1 && !root2) return NULL;

            Node* root = new Node();
            if (root1 && root2) {
                root->val = root1->val + root2->val;
            }

            if (!root1) root->val = root2->val;
            if (!root2) root->val = root1->val;

            // recursively merge
            root->left = mergeTrees(root1 ? root1->left: 0, root2 ? root2->left: 0);
            root->right = mergeTrees(root1 ? root1->right : 0, root2? root2->right: 0);

            return root;
        }
};
