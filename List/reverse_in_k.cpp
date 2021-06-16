struct node *reverse (struct node *head, int k)
{
    if (!head) return NULL;
    typedef node Node;
    Node* p = head;
    Node* q = p->next;
    Node* r;
    int count = 1;
    while (q && count++ < k) { // need to do k-1 link reversals.
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }

    head->next = reverse(q, k);
    return p;
}

