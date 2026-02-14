#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

class ListNode {
    public:
        int data;
        ListNode* next;
        ListNode* child;
        ListNode(int d) {
            data = d;
            next = NULL;
            child = NULL;
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

ListNode* flatteningLL_brute(ListNode* head) {
    vector<int> arr;
    ListNode* temp = head;
    while(temp!=NULL) {
        ListNode* t = temp;
        while(t!=NULL) {
            arr.push_back(t -> data);
            t = t -> child;
        }
        temp = temp -> next;
    }
    sort(arr.begin(), arr.end());
    ListNode* dummyNode = new ListNode(-1);
    ListNode* temp = dummyNode;
    int i = 0;
    while(i < arr.size()) {
        ListNode* newNode = new ListNode(arr[i++]);
        temp -> child = newNode;
        temp = temp -> child;
    }
    return dummyNode -> next;
}

ListNode* sortTwoLL(ListNode* t1, ListNode* t2) {
    ListNode* dummyNode = new ListNode(-1);
    ListNode* temp = dummyNode;
    while(t2!=NULL && t1!=NULL) {
        if(t1 -> data <= t2 -> data) {
            temp -> child = t1;
            t1 = t1 -> child;
            temp = temp -> child;
        } else {
            temp -> child = t2;
            t2 = t2 -> child;
            temp = temp -> child;
        }
    }
    if(t1) temp->child = t1;
    else temp->child = t2;
    return dummyNode -> child;
}
ListNode* flatteningLL_optimal(ListNode* head) {
    if(!head || !head->next)
        return head;

    head->next = flatteningLL_optimal(head->next);

    head = sortTwoLL(head, head->next);

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
    return 0;
}