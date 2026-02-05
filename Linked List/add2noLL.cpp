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

ListNode* addTwoNumbers_brute(ListNode* head1, ListNode* head2) {
    head1 = reverse(head1);
    head2 = reverse(head2);
    ListNode* temp1 = head1;
    ListNode* temp2 = head2;
    ListNode* dummyHead = new ListNode(-1);
    ListNode*  curr = dummyHead;
    int carry = 0;
    while(temp1!=NULL || temp2 != NULL) {
        int sum = carry;
        if(temp1!= NULL) {
            sum+= temp1 -> data;
        }
        if(temp2!= NULL) {
            sum+= temp2-> data;
        }

        curr -> next = new ListNode(sum%10);
        curr = curr -> next;
        carry = sum / 10;

        temp1 = temp1 == nullptr ? nullptr : temp1 -> next;
        temp2 = temp2 == nullptr ? nullptr : temp2 -> next;
    }
    if(carry == 1 ) {
        curr -> next = new ListNode(1);
    }
    return reverse(dummyHead -> next);
}

int main() {
    ListNode* head = new ListNode(2);
    ListNode* sec = new ListNode(4);
    ListNode* thrd = new ListNode(3);
    // ListNode* fr = new ListNode(9);

    ListNode* head2 = new ListNode(5);
    ListNode* sec2 = new ListNode(6);
    ListNode* thrd2 = new ListNode(4);
    ListNode* fr2 = new ListNode(9);

    head -> next = sec;
    sec -> next = thrd;
    thrd -> next = NULL;

    head2 -> next = sec2;
    sec2 -> next = thrd2;
    thrd2 -> next = fr2;
    fr2 -> next = NULL;

    ListNode* ans = addTwoNumbers_brute(head, head2);
    print(ans);

    return 0;
}