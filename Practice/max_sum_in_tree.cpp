struct ret_t {int cv; /*contained_value*/ int fv; /*flow_value;=*/};
    int MIN = ~(-1u >> 1);
    ret_t max_path(TreeNode* root)
    {

        if (!root) {
            return {MIN,0};
        }
        
        ret_t l = max_path(root->left);
        ret_t r = max_path(root->right);
        
        
        ret_t rt;
        rt.fv = max(max(l.fv,r.fv)+root->val, root->val);
        rt.cv = max(max(l.cv, r.cv), max(l.fv+r.fv+root->val, rt.fv));
        
        return rt;
    }
    
    int maxPathSum(TreeNode* root) {
        ret_t ret = max_path(root);
        return ret.cv;
    }

can use INT_MAX, INT_MIN for max and min integers.