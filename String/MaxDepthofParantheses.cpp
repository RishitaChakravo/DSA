#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int depthofParantheses(string s) {
    int depth = 0;
    int d = 0;
    for(int i = 0 ; i < s.size(); i++) {
        if(s[i] == '(') d++;
        if(s[i] == ')') {
            depth = max(d, depth);
            d--;
        }
    }
    return depth;
}
int main() {
    string s = "(1+(2*3)+((8)/4))+1";
    cout << depthofParantheses(s);
    return 0;
}