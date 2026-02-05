#include<iostream>
#include<map>
#include<vector>
#include<set>
using namespace std;

class ListNode {
    public:
        int data;
        ListNode* next;
        ListNode(int d) {
            data = d;
            next = NULL;
        }
};

void print(ListNode* head) {
    ListNode* temp = head;
    while(temp !=NULL) {
        cout << temp->data << "->";
        temp = temp -> next;
    }
    cout <<"NULL"<< endl;
}

ListNode* reverse(ListNode* head) {
    ListNode* prev= NULL, *curr = head, *next=NULL;
    while(curr!=NULL) {
        next = curr -> next;
        curr -> next = prev;
        prev= curr;
        curr = next;
    }
    head = prev;
    return head;
}

ListNode* addOne_brute(ListNode* head) {
    head = reverse(head);
    ListNode* temp = head;
    int carry = 1;
    while(temp!=NULL) {
        temp -> data = temp -> data + carry;
        if(temp -> data < 10) {
            carry = 0;
            break;
        } else {
            temp -> data = 0;
            carry = 1;
        }
        temp = temp -> next;
    }
    head = reverse(head);
    if(carry == 1) {
        ListNode* newHead = new ListNode(1);
        newHead -> next = head;
        head = newHead;
    }
    return head;
}

int optimal_recursive(ListNode* node) {
    if(node == NULL) return 1;
    int carry = optimal_recursive(node -> next);
    node -> data = node -> data + carry;
    if(node -> data < 10) {
        carry = 0;
    } else {
        node -> data = 0;
        carry = 1;
    }
    return carry;
}

ListNode* addOne_optimal(ListNode* head) {
    int carry = optimal_recursive(head);
    if(carry == 1) {
        ListNode* newHead = new ListNode(1);
        newHead -> next = head;
        head = newHead;
    }
    return head;
}

int main() {
    ListNode* head = new ListNode(9);
    ListNode* sec = new ListNode(9);
    ListNode* thrd = new ListNode(9);
    ListNode* fr = new ListNode(9);

    head -> next = sec;
    sec -> next = thrd;
    thrd -> next = fr;
    fr -> next = NULL;

    head = addOne_optimal(head);
    print(head);

    return 0;
}