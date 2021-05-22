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

int find_nthnode_from_end(Node* head, int n, int* end_count)
{
    if (head == nullptr) {
        return -1;
    }
    
    if (head->next == nullptr) {
        *end_count = 1;
        if (*end_count == n) return head->data;
        return -1;
    }
    
    int ret = find_nthnode_from_end(head->next, n, end_count);

    if (ret != -1) return ret; // found already
    
    (*end_count)++;
    if (n == *end_count) return head->data;
    
    return -1;
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
    return p;
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
    int end_count(0);
    cout << find_nthnode_from_end(head, 1, &end_count);
    return 0;
}




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

Node* construct(int* a, int i, int size)
{
    if (i >= size) return NULL;
    Node * head = new Node(a[i]);
    head->next = construct(a, i+1, size);
    return head;
}

void print(Node* head)
{
    while (head != 0) { cout << head->data << " ";  head = head->next;}
    cout << endl;
}

Node* merge_list(Node* h1, Node* h2)
{
    Node* head = h1;
    Node* ph1;
    while (h1 != NULL && h2 != NULL) {
        while (h1->data <= h2->data) {
            ph1 = h1; h1 = h1->next;
            if (h1 == NULL) break;
        }
        
        // insert h2 after ph1
        Node* nh2 = h2->next;
        ph1->next = h2;
        h2->next = h1;
        ph1 = h2;
        h2 = nh2;
    }
    
    if (h2 != NULL) {
        ph1->next = h2;
    } 
    
    return head;
}

Node* merge_recursive(Node* h1, Node* h2)
{
   if (!h1) return h2;
   if (!h2) return h1;
   if (h1->data < h2->data) {
       h1->next = merge_recursive(h1->next, h2);
       return h1;
   } else {
       h2->next = merge_recursive(h1, h2->next);
       return h2;
   }
}

int main()
{
    int a[] = {1,2,5,6,8};
    int b[] = {3,4,7,9};
    
    Node* h1 = construct(a, 0, 5);
    Node* h2 = construct(b, 0, 4);
    //print(h1);
    //print(h2);
    
    Node *mh = merge_recursive(h1, h2);
    print(mh);

    return 0;
}


Node* reverse_iterative(Node* head, int k)
{
    if (!head) return head;
    
    Node* tail = head->next;
    Node* oh = head;
    
    int count(0);
    while (tail && ++count < k) {
        Node* next = tail->next;
        tail->next = head;
        head = tail;
        tail = next;
    }
    
    oh->next = tail;
    
    return head;
}

Node* reverse_in_group(Node* head, int k)
{
    if (!head) return head;
    
    // reverse k elements
    Node* nh = reverse_iterative(head, k);
    Node* tail = head;
    tail->next = reverse_in_group(tail->next, k);
    return nh;
}


bool is_palindrome(Node* head, Node*& begin)
{
    if (!head) return true;
    if (!is_palindrome(head->next, begin)) return false;;
    if (head->data != begin->data) {
        return false;
    }
    
    begin = begin->next;
    return true;
}

