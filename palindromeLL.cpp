#include<iostream>
#include<stack>
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

bool check_palindrome_brute(Node* head) {
    stack<int> st;
    Node* temp = head;
    while(temp != NULL) {
        st.push(temp -> data);
        temp = temp -> next;
    }
    temp = head;
    while(temp!=NULL) {
        if(temp -> data != st.top()) return false;
        st.pop();
        temp = temp -> next;
    }
    return true;
}

Node* reverse(Node* head) {
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    while(curr != NULL) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}

bool check_palindrome_optimal(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while(fast -> next != NULL && fast -> next -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    Node* second = reverse(slow -> next);
    Node* first = head;
    while(second!= NULL) {
        if(first -> data != second -> data) {
            reverse(slow -> next);
            return false;
        }
        second = second -> next;
        first = first -> next;
    }
    reverse(slow -> next);
    return true;
}

int main() {
    Node* head = new Node(3);
    Node* sec = new Node(7);
    Node* thrd = new Node(5);
    Node* fr = new Node(7);
    Node* fve = new Node(3);

    head -> next = sec;
    sec -> next = thrd;
    thrd -> next = fr;
    fr -> next = fve;
    
    cout << check_palindrome_optimal(head);
    
    return 0;
}