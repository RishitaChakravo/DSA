#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string expand(string s, int i, int j) {
    while(i >= 0 && j < s.size()&& s[i] == s[j]) {
        i--;
        j++;
    }
    return s.substr(i+1, j-i-1);
}

string longestPalindromicSubstr(string s) {
    string ans = "";
    for(int k = 0; k < s.size(); k++) {
        string odd = expand(s, k, k);
        string even = expand(s, k, k+1);

        if(odd.size() > ans.size()) ans = odd;
        if(even.size() > ans.size()) ans = even;
    }
    return ans;
}
int main() {
    string s = "babad";
    cout <<longestPalindromicSubstr(s);
    return 0;
}