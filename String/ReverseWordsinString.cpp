#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string reversewords1(string s) {
    vector<string> v;
    string word = "";
    for(char c : s ) {
        if(c == ' ') {
            if(!word.empty()){
                v.push_back(word);
                word = "";
            }
        } else {
            word += c;
        }
    }
    if(!word.empty()) {
        v.push_back(word);
    }
    reverse(v.begin(), v.end());
    string result = "";
    for(int i = 0; i < v.size(); i++) {
        result += v[i];
        if (i != v.size() - 1) {
            result += " ";
        }
    }
}

string reverseWords2(string s) {
    string result;
    int i = s.size();
    int r = 0, l = 0;
    while(i >=0 ) {
        while(i >= 0 && s[i] == ' ') i--;
        if (i < 0) break;
        int end = i;
        while(i >= 0 && s[i]!=' ') {
            i--;
        }
        int start = i + 1;
        if (!result.empty()) result += " ";
        result += s.substr(start, end - start + 1);
    }
    return result;
}
int main() {
    string result = reverseWords2("   hello world    "); 
    cout <<  result;
    return 0;
}