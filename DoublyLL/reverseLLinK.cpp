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

void reverse(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* next = NULL;
    while(curr!=NULL) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
}

ListNode* KthNode(ListNode* temp, int k) {
    k -= 1;
    while(temp!=NULL && k > 0) {
        temp = temp -> next;
        k--;
    }
    return temp;
}

ListNode* reverseLLforKgrp_brute(ListNode* head, int k) {
    ListNode* temp = head;
    ListNode* prevNode = NULL;

    while(temp != NULL) {
        ListNode* kthNode = KthNode(temp, k);

        if(kthNode == NULL) {
            if(prevNode) prevNode->next = temp;
            break;
        }

        ListNode* nextNode = kthNode->next;
        kthNode->next = NULL;

        reverse(temp);

        if(temp == head) {
            head = kthNode;
        } else {
            prevNode->next = kthNode;
        }

        prevNode = temp;   
        temp = nextNode;   
    }
    return head;
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
    ListNode* newHead = reverseLLforKgrp_brute(head, 2);
    print(newHead);
    return 0;
}