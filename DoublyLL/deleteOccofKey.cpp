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

ListNode* deleteOccofKey(ListNode* head, int target) {
    if(head == NULL) return NULL;
    ListNode* curr = head;
    while(curr!=NULL) {
        if(curr -> data == target) {
            if(curr -> prev == NULL) {
                head = curr -> next;
                head -> prev = NULL;
            }else if(curr -> next == NULL) {
                curr -> prev -> next = curr -> next;
            } else {
                curr -> prev -> next = curr -> next;
                curr -> next -> prev = curr -> prev;
            }
            curr = curr -> next;
        } else {
            curr = curr -> next;
        }
    }
    return head;
}
int main() {
    ListNode* head = new ListNode(1);
    ListNode* sec = new ListNode(1);
    ListNode* thr = new ListNode(1);
    ListNode* fr = new ListNode(1);
    ListNode* fve = new ListNode(1);
    ListNode* six = new ListNode(4);
    ListNode* svn = new ListNode(1);

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

    head = deleteOccofKey(head, 1);
    print(head);
    return 0;
}