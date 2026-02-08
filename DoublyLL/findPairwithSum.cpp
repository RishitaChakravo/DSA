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

void findPairwithSum_brute(ListNode* head, int sum) {
    ListNode* temp = head;
    while(temp!=NULL) {
        ListNode* t = temp -> next;
        while(t!=NULL && temp -> data + t -> data <= sum) {
            if(t->data + temp -> data == sum) {
                cout << "(" << temp -> data << ", " << t -> data << ")" << " ";
            }
            t = t -> next;
        }
        temp = temp -> next;
    }
}

void findPairwithSum_optimal(ListNode* head, int sum) {
    ListNode* left = head;
    ListNode* right = head;
    while(right -> next != NULL) {
        right = right -> next;
    }
    while(left -> data <= right -> data) {
        if(left -> data + right -> data == sum) {
            cout << "(" << left -> data << ", " << right -> data << ")" << " ";
            left = left -> next;
            right = right -> prev;
        } else if(left -> data + right -> data > sum) {
            right = right -> prev;
        } else {
            left = left -> next;
        }
    }
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

    findPairwithSum_optimal(head, 7);
    return 0;
}