int size(Node* root)
{
    if (!root) return 0;
    return max(size(root->left), size(root->right)) + 1;
}


// every node has 0 or 2 children
bool full(root)
{
    if (!root) return true;

    if (!root->left && !root->right) return true;
    if (!root->left || !root->right) return false;

    return full(root->left) && full(root->right);
}


// check if BT is perfect
bool perfect(root, int level, int ll/*leaf level*/)
{
    if (!root) return true;
    if (!root->left && !root->right) {
        return (level == ll);
    }
    if (!root->left || !root->right) return false;
    return prefect(root->left, level+1, ll) && perfect(root->right, level+1, ll);
}


bool complete(root, int i, int size)
{
    if i > size return false;  //during traversal
}

// complete meaning all inorderd predecessor should be in order - thats it
// or can be done alternatively by initially finding the size of the tree and comparing pos
bool complete(root, int& apos, int epos)
{
    if (!root) return true;

    if (!root->left && !root->right) {
        apos++;
        return (apos == epos)
    }
    if (!root->left || !root->right) return false;

    return 
        complete(root->left, apos, epos*2+1) &&
        complete(root->left, apos, epos*2+2);
}


// mirror tree
mirror(root)
{
    if (!root) return root;
    mirror(root->left);
    mirror(root->right);
    swap(root->left, root->right);
}
