#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool rotateString(string s, string t) {
    if(s.size() != t.size()) return false;
    int i = 0;
    string check;
    while(i < t.size()) {
        check = s.substr(i) + s.substr(0,i);
        if(t.compare(check) == 0) return true;
        i++;
    }
    return false;
}

bool rotateString_optimal(string s, string t) {
    string str = s + s;
    int i = 0;
    while(i < s.size()) {
        if(t.compare(str.substr(i, s.size())) == 0) return true;
        i++; 
    }
    return false;
}
int main() {
    string s = "defdefdefabccb";
    string t = "defdefabccbdef";
    cout << rotateString_optimal(s, t);
    return 0;
}