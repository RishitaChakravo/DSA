#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isomorphicString(string s, string t) {
    if(s.size()!= t.size()) return false;
    int i = 0;
    unordered_map<char, char> mpp1;
    unordered_map<char, char> mpp2;
    for(int i = 0 ; i < s.size(); i++) {
        char a = s[i];
        char b = t[i];
        if((mpp1.count(a)) && mpp1[a] != b) return false;
        if((mpp2.count(b)) && mpp2[b] != a) return false;

        mpp1[a] = b;
        mpp2[b] = a;
    }
    return true;
}

int main() {
    string s = "foo";
    string t = "bar";
    cout << isomorphicString(s, t);
    return 0;
}