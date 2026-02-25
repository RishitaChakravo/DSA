#include<iostream>
#include <bits/stdc++.h>

using namespace std;

int cntSubString_brute(string s) {
    int numSubStrings = 0;
    for(int i = 0; i < s.size(); i++) {
        int a = 0, b = 0, c = 0;
        for(int j = i; j < s.size(); j++) {
            if(s[j] == 'a') a = 1;
            if(s[j] == 'b') b = 1;
            if(s[j] == 'c') c = 1;

            if(a && b && c) numSubStrings++;
        }
    }
    return numSubStrings;
}
int cntSubString_optimal(string s){
    int numSubStrings = 0;
    int l = 0, r = 0;
    int n = s.size();
    int a = 0, b = 0, c = 0;
    while(r < s.size()) {
        if(s[r] == 'a') a++;
        if(s[r] == 'b') b++;
        if(s[r] == 'c') c++;
        while(a&&b&&c) {
            numSubStrings += n - r;
            if(s[l] == 'a') a--;
            if(s[l] == 'b') b--;
            if(s[l] == 'c') c--;
            l++;
        }
        r++;
    }
    return numSubStrings;
}
int main() {
    string s = "abcabc";
    cout << cntSubString_optimal(s);
    return 0;
}