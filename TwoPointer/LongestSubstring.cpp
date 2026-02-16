#include<iostream>
#include <bits/stdc++.h>

using namespace std;

int longestSubstring_brute(string s) {
    int maxsize = 0;
    for(int i = 0; i < s.size(); i++) {
        map<char, int> mpp;
        for(int j = i; j < s.size(); j++) {
            if(mpp.find(s[j]) == mpp.end()) {
                mpp[s[j]] = 1;
                maxsize = max(maxsize, j - i + 1);
            } else {
                break;
            }
        }
    }
    return maxsize;
}

int longestSubstring_optimal(string s) {
    int maxsize = 0;
    int i = 0, j = 0;
    unordered_map<char, int> mpp;
    while(j < s.size()) {
        if(mpp.find(s[j]) == mpp.end()) {
            mpp[s[j]] = 1;
            maxsize = max(maxsize, j - i + 1);
            j++;
        } else {
            mpp.erase(s[i]);
            i++;
        }
    }
    return maxsize;
}
int main() {
    string s ="abcddabac";
    cout << longestSubstring_optimal(s);
    return 0;
}