// nothing but first element of each level

void left_view(root, int l, int& ml)
{
    if (!root) return;
    if (l > ml) {
        print(root);
        ml = l;
    }

    left_view(root->left, l+1, ml);
    left_view(root->right, l+1, ml);
    // just reverse the order to get the right view
}

// spiral etc. bfs

// vertical view 

