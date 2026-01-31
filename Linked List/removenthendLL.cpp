// remove nth element from the end of the linked list
#include<iostream>
#include<map>
#include<vector>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node(int d) {
            data = d;
            next = NULL;
        }
};

void print(Node* head) {
    Node* temp = head;
    while(temp !=NULL) {
        cout << temp->data << "->";
        temp = temp -> next;
    }
    cout <<"NULL"<< endl;
}

void removenthendElement_brute(Node* head, int n) {
    if(head == NULL) return;
    int l = 0;
    Node* temp = head;
    while(temp != NULL) {
        l++;
        temp = temp -> next;
    }
    if(n > l) return;

    int del = l - n;

    if(del == 0) {
        Node* todel = head;
        head = head -> next;
        delete(todel);
        return;
    }

    temp = head;
    
    for(int i = 1; i < del; i++) {
        temp = temp -> next;
    }
    
    Node* todel = temp -> next;
    temp -> next = todel -> next;
    delete(todel);
}

Node* removenthendElement_optimal(Node* head, int n) {
    Node* fast = head;
    for(int i = 0; i <= n; i++) {
        fast = fast -> next;
    }
    if(fast == NULL) return head -> next;
    Node* slow = head;
    while(fast->next!=NULL) {
        slow = slow-> next; // fast should be at the last node not the null
        fast = fast-> next;
    }
    Node* todel = slow -> next;
    slow->next =todel -> next;
    free(todel);
    return head;
}

int main() {
    Node* head = new Node(1);
    Node* sec = new Node(2);
    Node* thrd = new Node(3);
    Node* fr = new Node(4);
    Node* fve = new Node(5);
    Node* six = new Node(6);

    head -> next = sec;
    sec -> next = thrd;
    thrd -> next = fr;
    fr -> next = fve;
    fve -> next = six;

    print(head);
    removenthendElement_optimal(head, 3);
    print(head);

    return 0;
}