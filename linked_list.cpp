/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

struct Node {
  Node(int d) : data(d), next(0) {}
 
  int data;
  Node* next;
};

void construct(Node *&head, Node* &tail, int* a, int i, int size)
{
    if (i > size) return;
    Node* n = new Node(a[i]);
    if (!head) {head = n; tail = head; }
    else {
        tail->next = n;
        tail = n;
    }
    
    construct(head, tail, a, i+1, size);
}

void print(Node* head)
{
    while (head != 0) { cout << head->data << " ";  head = head->next;}
    cout << endl;
}

void insert_after(Node* curr, int after, int el)
{
   while (curr != nullptr) {
       if (curr->data == after) {
           Node * n = new Node(el);
           n->next = curr->next;
           curr->next = n;
           return;
       }
       curr = curr->next;
   }
}

void insert_before(Node*& head, int before, int el)
{
    if (head->data == before) {
        Node *n = new Node(el);
        n->next = head;
        head = n;
        return;
    }
    Node *curr = head->next;
    Node *prev = head;
    
    while (curr->next != nullptr)
    {
        if (curr->data == before) {
            Node* n = new Node(el);
            n->next = curr;
            prev->next = n;
            return;
        }
        
        prev = curr;
        curr = curr->next;
    }
}

void delete_node(Node*& head, int el)
{
    if (head->data == el) {
        Node* newhead = head->next;
        delete head;
        head = newhead;
        return;
    }
    
    Node* prev = head;
    Node* curr = head->next;
    while (curr != nullptr) {
        if (curr->data == el) {
            prev->next = curr->next;
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

Node* reverse(Node* head)
{
    if (!head || !head->next) return head;
    Node* tail = reverse(head->next);
    head->next->next = head;
    head->next = nullptr;
    
    return tail;
}

Node* reverse_iterative(Node* head)
{
    if (!head || !head->next) return head;
    Node* p = head;
    Node* q = head->next;
    head->next = nullptr;
    
    while (q != nullptr) {
        Node * r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
}

int main()
{
    int a[] = {1,2,3,4,5,6};
    Node *head(0);
    Node *tail;

    construct(head, tail, a, 0, 5);
    print(head);

    delete_node(head, 4);
    delete_node(head, 6);
    delete_node(head, 1);
    
    insert_after(head, 3,4);
    insert_after(head, 5,6);
    
    insert_before(head, 2, 1);
    
    delete_node(head, 4);
    insert_before(head, 5, 4);
    
    head = reverse(head);
    head = reverse_iterative(head);
    print(head);
    return 0;
}
