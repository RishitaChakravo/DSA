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

int lengthLoop_brute(Node* head) {
    int i = 0;
    map<Node*,int> mpp;
    Node* temp = head;
    while(temp != NULL) {
        i++;
        if(mpp.find(temp) != mpp.end()){
            return i - mpp[temp];
        }
        mpp[temp] = i;
        temp = temp -> next;
    }
    return 0;
}
int lengthLoop_optimal(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast) {
            int cnt = 1;
            fast = fast -> next;
            while(slow != fast) {
                cnt++;
                fast = fast -> next;
            }
            return cnt;
        }
    }
    return 0;
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

    cout << lengthLoop_optimal(head);
    
    return 0;
}