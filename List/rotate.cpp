 Node* rotate(Node* head, int k)
    {
        Node* nh = head;
        int i(0);
        while (nh->next != 0 && ++i < k) nh = nh->next;
        if (nh->next == 0) return head;
        Node* r = nh->next;
        while(r->next != 0) r = r->next;
        r->next = head;
        head = nh->next;
        nh->next = 0;
        
        return head;
    }
