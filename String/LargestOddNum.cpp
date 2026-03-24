#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string largestOddNum(string s){
    int start = 0;
    int end = s.size() - 1;
    while(end >= 0) {
        if(s[end] != '3' && s[end] != '5' && s[end] != '7'&& s[end] != '1'&& s[end] != '9'){
            end--;
        } else {
            break;
        }
    }
    while(start < s.size()) {
        if(s[start] == '0') {
            start++;
        } else {
            break;
        }
    }
    string result = s.substr(start, end - start + 1);
    return result;
}
int main() {
    string s = "98712356";
    cout << largestOddNum(s);
    return 0;
}