//delete the middle of the linked list
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

void deleteMiddle_optimal(Node* head) {
    if(head == NULL) return;
    Node* fast = head ->next -> next;
    Node* slow = head;
    while(fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    Node* todel = slow -> next;
    slow -> next = todel -> next;
    delete todel;
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
    deleteMiddle_optimal(head);
    print(head);

    return 0;
}