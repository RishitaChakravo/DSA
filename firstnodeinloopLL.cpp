#include<iostream>
#include<map>
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

// same for detetct a loop
Node* firstNode_Loop_brute(Node* head){
    map<Node*, int> mpp;
    Node* temp = head;
    while(temp != NULL) {
        if(mpp.find(temp) != mpp.end()){
            return temp;
        }
        mpp[temp] = 1;
        temp = temp -> next;
    }
    return NULL;
}

Node* firstNode_loop_optimal(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while(fast -> next != NULL && fast != NULL) {
        if(slow == fast){
            slow = head;
            while(slow != fast) {
                slow = slow -> next;
                fast = fast -> next;
            }
            return slow;
        }
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return NULL;
}

int main() {
    Node* head = new Node(1);
    Node* sec = new Node(2);
    Node* thrd = new Node(3);
    Node* fr = new Node(4);
    Node* fve = new Node(5);

    head -> next = sec;
    sec -> next = thrd;
    thrd -> next = fr;
    fr -> next = fve;
    fve -> next = thrd;
    
    return 0;
}