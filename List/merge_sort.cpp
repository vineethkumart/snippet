#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    
    Node* merge(Node* l, Node* r)
    {
        if (l == NULL) return r;
        if (r == NULL) return l;
        
        if (l->data < r->data) {
            l->next = merge(l->next, r);
            return l;
        }
        
        r->next = merge(l, r->next);
        return r;
    }
    
    Node* mergeSort(Node* head) {
        if (!head || !head->next) return head;
        
        // go to middle of the list
        Node* s, *f;
        s = head;
        f = head;
        
        while (f != NULL && f->next != NULL 
                    && f->next->next != NULL) {
            s = s->next;
            f = f->next->next;
        }
        
        f = s->next;
        s->next = NULL;
        Node* p1 = mergeSort(head);
        Node* p2= mergeSort(f);
        
        Node* n = merge(p1, p2);
        return n;
    }
};
