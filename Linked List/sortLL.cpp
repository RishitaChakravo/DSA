#include<iostream>
#include<map>
#include<vector>
#include<set>
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

void sortLL_brute(Node* head) {
    multiset<int> st;
    Node* temp = head;
    while(temp != NULL) {
        st.insert(temp -> data);
        temp = temp -> next;
    }
    temp = head;
    for(int x : st){
        temp -> data = x;
        temp = temp -> next;
    }
}

Node* merge(Node* left, Node* right) {
    Node* newHead=new Node(-1);
    Node* temp = newHead;
    while(left != NULL && right != NULL){
        if(left -> data <= right -> data) {
            temp -> next = left;
            temp = left;
            left = left -> next;
        } else {
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
    }
    if(left) temp -> next = left;
    else temp -> next = right;
    return newHead-> next;
}

Node* mergesort(Node* head) {
    if(head==NULL || head -> next == NULL) return head;
    Node* slow = head;
    Node* fast = head;
    while(fast -> next !=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* left = head;
    Node* right = slow -> next;
    slow -> next = NULL;
    left = mergesort(left);
    right = mergesort(right);
    return merge(left, right);
}

int main() {
    Node* head = new Node(3);
    Node* sec = new Node(4);
    Node* thrd = new Node(1);
    Node* fr = new Node(5);
    Node* fve = new Node(6);
    Node* six = new Node(2);

    head -> next = sec;
    sec -> next = thrd;
    thrd -> next = fr;
    fr -> next = fve;
    fve -> next = six;

    print(head);
    Node* newhead = mergesort(head);
    print(newhead);

    return 0;
}