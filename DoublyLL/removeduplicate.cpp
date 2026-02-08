#include<iostream>
#include<map>
#include<vector>
#include<set>
using namespace std;

class ListNode {
    public:
        int data;
        ListNode* next;
        ListNode* prev;
        ListNode(int d) {
            data = d;
            next = NULL;
            prev = NULL;
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

void removeDuplicate(ListNode* head) {
    ListNode* temp = head -> next;
    ListNode* prev = head;
    while(temp != NULL) {
        if(prev -> data == temp -> data){
            if(temp -> next == NULL) {
                prev -> next = NULL;
            } else {
                prev -> next = temp -> next;
                temp -> next -> prev = prev;
            }
        }
        prev = temp;
        temp = temp -> next;
    }
}

int main() {
    ListNode* head = new ListNode(1);
    ListNode* sec = new ListNode(2);
    ListNode* thr = new ListNode(2);
    ListNode* fr = new ListNode(4);
    ListNode* fve = new ListNode(5);
    ListNode* six = new ListNode(6);
    ListNode* svn = new ListNode(6);

    head -> next = sec;
    sec -> prev = head;
    sec -> next = thr;
    thr -> prev = sec;
    thr -> next = fr;
    fr -> prev = thr;
    fr -> next = fve;
    fve -> prev = fr;
    fve -> next = six;
    six -> prev = fve;
    six -> next = svn;
    svn -> prev = six;
    print(head);
    removeDuplicate(head);
    print(head);
    return 0;
}