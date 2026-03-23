#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string removeParantheses1(string s){
    string ans = "";
    stack<char> st;
    for(char c:s){
        if(c == '(') {
            if(!st.empty()) {
                ans += c;
            }
            st.push(c);
        } else {
            st.pop();
            if(!st.empty())  {
                ans += c;
            }
        } 
    }
    return ans;
}
string removeParantheses2(string s) {
    int counter = 0;
    string ans = "";
    if(s == "") return s;
    for(char c : s) {
        if(c == '(') {
            if(counter != 0) {
                ans+=c;
            }
            counter++;
        } else {
            counter--;
            if(counter!=0) {
                ans+=c;
            }
        }
    }
    return ans;
}
int main(){
    string ans = removeParantheses2("(()())((()))");
    cout << ans;
    return 0;
}