#include<iostream>
#include<map>
#include<vector>
#include<set>
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

void print(Node* head) {
    Node* temp = head;
    while(temp !=NULL) {
        cout << temp->data << "->";
        temp = temp -> next;
    }
    cout <<"NULL"<< endl;
}

Node* findIntersection_brute(Node* head1, Node* head2) {
    map<Node*, int> mp;
    Node* temp = head1;
    while(temp!=NULL) {
        mp[temp] = 1;
        temp =  temp -> next;
    }
    temp = head2;
    while(temp!=NULL) {
        if(mp.find(temp)!=mp.end()) {
            return temp;
        }
        temp = temp -> next;
    }
    return NULL;
}

Node* better(Node* head1, Node* head2) {
    Node* temp1 = head1;
    Node* temp2 = head2;
    int cnt1 = 0, cnt2 = 0;
    while(temp1 !=NULL) {
        cnt1++;
        temp1 = temp1 -> next;
    }
    while(temp2 !=NULL) {
        cnt2++;
        temp2 = temp2 -> next;
    }
    temp1 = head1; 
    temp2 = head2;
    if(cnt1 > cnt2) {
        int cnt = cnt1 - cnt2;
        while(cnt > 0) {
            cnt--;
            temp1 = temp1 -> next;
        }
    } else if(cnt1 < cnt2) {
        int cnt = cnt2 - cnt1;
        while(cnt > 0) {
            cnt--;
            temp2 = temp2 -> next;
        }
    }

    while(temp1!=NULL && temp2!=NULL) {
        if(temp1 == temp2) {
            return temp1;
        }
        temp1 = temp1 -> next; 
        temp2 = temp2 -> next;
    }
    return NULL;
}

Node* optimal(Node* head1, Node* head2) {
    Node* temp1 = head1;
    Node* temp2 = head2;
    while(temp1!=temp2) {
        temp1 = (temp1 == nullptr) ? head2 : temp1->next;
        temp2 = (temp2 == nullptr) ? head1 : temp2->next;
    }
    return temp1;
}

int main() {
    Node* head = new Node(1);
    Node* sec = new Node(3);
    Node* thrd = new Node(1);
    Node* fr = new Node(2);
    Node* fve = new Node(4);
    Node* six = new Node(1);
    Node* head2 = new Node(3);

    head -> next = sec;
    sec -> next = thrd;
    thrd -> next = fr;
    fr -> next = fve;
    fve -> next = six;
    head2 -> next = fr;
    fr -> next = fve;
    fve -> next = six;

    Node* ans = optimal(head, head2);
    cout << ans -> data;

    return 0;
}