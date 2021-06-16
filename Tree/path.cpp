bool path(Node* root, int el, vector<int> path)
{
    if (!root) return true;

    // push
    path.push(root);
    if (root->data == el) {
        // print the path
        return true;
    }

    bool f = path(root->left, el, path);
    if (f) return true;
    f = path(root->right, el, path);
    if (f) return true;

    path.pop_back(root); // backtrack
    return false;
}

// shortest path root -> leaf in a tree and longest path in a tree
p = INT_MAX;
void sp(root, int& p, int h)
{
    if (!root) return;
    if (!root->left && !root->right) {
        p = min(h, p);
        return;
    }

    sp(root->left, p, h+1);
    sp(root->right, p, h+1);
}

int sp(root)
{
    if (!root) return 0;
    return 1 + min(sp(root->left), sp(root->right));
}
// root - left
int lp(root)
{
    if (!root) return 0;
    return 1 + max(lp(root->left), lp(root->right));
}

// find the longest path in a abrorescens
// 1. take any node and do a DFS to find the farthest node
// 2. Take that node as the start node and do another dfs to farthest node.

// Can do using BFS as well - Better solution, no need to traverse all. first leaf you find will surely be the lowest leaf



bool path_with_sum(root, sum, vector<int> path)
{
    if (!root) return false;
    path.push(root);
    if (sum == 0) {
        // found a path print
        return true;
    }

    bool found = path_with_sum(root->left, sum-root->data, path);
    if (found) return true;
    found = path_with_sum(root->right, sum-root->data, path);
    if (found) return true;

    path.pop(root);
    return false;
}










