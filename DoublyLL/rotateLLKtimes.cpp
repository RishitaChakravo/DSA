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

ListNode* rotateLL(ListNode* head, int k) {
    if(!head||head -> next == NULL||k==0) return head;
    ListNode* t= head;
    int len = 0;
    while(t != NULL) {
        t = t-> next;
        len++;
    }
    k = k % len;
    if(k == 0) return head; 
    while(k > 0) {
        ListNode* temp = head;
        while(temp -> next -> next!=NULL) {
            temp = temp-> next;
        }
        ListNode* last = temp -> next;
        temp -> next = NULL;
        last -> next = head;
        head = last;
        k--;
    }
    return head;
}

ListNode* rotateLL_optimal(ListNode* head, int k) {
    ListNode* tail = head;
    int len = 1;
    while(tail -> next) {
        tail = tail -> next;
        len++;
    }
    k = k % len;
    if(k==0) return head;
    tail -> next = head;
    int step = len - k;
    ListNode* newtail = tail;
    while(step > 0) {
        newtail = newtail -> next;
        step--;
    }

    ListNode* newHead = newtail -> next;
    newtail -> next = NULL;
    return newHead;
}


int main() {
    ListNode* head = new ListNode(1);
    ListNode* sec = new ListNode(2);
    ListNode* thr = new ListNode(3);
    ListNode* fr = new ListNode(4);
    ListNode* fve = new ListNode(5);
    ListNode* six = new ListNode(6);
    ListNode* svn = new ListNode(7);

    head -> next = sec;
    sec -> next = thr;
    thr -> next = fr;
    fr -> next = fve;
    fve -> next = six;
    six -> next = svn;
    print(head);
    ListNode* newHead = rotateLL_optimal(head, 2);
    print(newHead);
    return 0;
}