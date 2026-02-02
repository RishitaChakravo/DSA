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

Node* sort012_brute(Node* head){
    vector<int> v(3);
    Node* temp= head;
    while(temp!=NULL){
        v[temp -> data]++;
        temp = temp -> next;
    }
    temp = head;
    while(v[0] > 0) {
        temp -> data = 0;
        temp = temp -> next;
        v[0]--;
    }
    while(v[1] > 0) {
        temp -> data = 1;
        temp = temp -> next;
        v[1]--;
    }
    while(v[2] > 0) {
        temp -> data = 2;
        temp = temp -> next;
        v[2]--;
    }
    return head;
}

Node* sort012_optimal(Node* head) {
    Node* zeroHead = new Node(-1), *zeros = zeroHead;
    Node* oneHead = new Node(-1), *ones = oneHead;
    Node* twoHead = new Node(-1), *twos = twoHead;
    Node* temp = head;
    while(temp!=NULL) {
        if(temp -> data == 0) {
            zeros -> next = temp;
            zeros = temp;
        } else if(temp -> data == 1) {
            ones -> next = temp;
            ones = temp;
        } else {
            twos -> next = temp;
            twos = temp;
        }
        temp=temp->next;
    }
    // if no zeros it will already point to onehead or twohead using this statement so its fine 
    zeros -> next = (oneHead -> next) ? oneHead -> next : twoHead -> next;
    ones -> next = twoHead -> next;
    twos-> next =  NULL;
    head = zeroHead -> next;
    return head;
}

int main() {
    Node* head = new Node(1);
    Node* sec = new Node(0);
    Node* thrd = new Node(2);
    Node* fr = new Node(0);
    Node* fve = new Node(1);
    Node* six = new Node(2);

    head -> next = sec;
    sec -> next = thrd;
    thrd -> next = fr;
    fr -> next = fve;
    fve -> next = six;

    print(head);
    Node* newhead = sort012_optimal(head);
    print(newhead);

    return 0;
}