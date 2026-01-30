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

void insertNode(Node** head, int d) {
    Node* newNode = new Node(d);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

Node* segregate(Node* head) {
    Node* temp = head;
    Node* even = NULL;
    Node* odd= NULL;
    while(temp != NULL) {
        if(temp -> data %2 == 0) {
            insertNode(&even, temp->data);
        } else {
            insertNode(&odd, temp->data);
        }
        temp = temp -> next;
    }
    if (even == NULL) return odd;

    Node* t = even;
    while (t->next != NULL) {
        t = t->next;
    }
    t->next = odd;

    return even;
}

void print(Node* head) {
    Node* temp = head;
    while(temp !=NULL) {
        cout << temp->data << "->";
        temp = temp -> next;
    }
    cout <<"NULL"<< endl;
}

Node* segregate_better(Node* head) {
    vector<int> v;
    Node* temp = head;
    while(temp != NULL && temp -> next != NULL) {
        v.push_back(temp-> data);
        temp = temp -> next -> next;
    }
    if(temp!=NULL) v.push_back(temp->data);
    temp = head -> next;
    while(temp != NULL && temp -> next != NULL) {
        v.push_back(temp-> data);
        temp = temp -> next -> next;
    }
    int i = 0;
    temp = head;
    while(temp!=NULL) {
        if(v[i] != temp -> data) {
            temp -> data = v[i];
        } 
        temp = temp -> next;
        i++;
    }
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

    Node* segregated = segregate(head);
    print(head);
    print(segregated);
    return 0;
}