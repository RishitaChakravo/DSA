#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int LongestSubstringWithKChar_brute(string s, int k) {
    int maxlen = 0;
    for(int i = 0; i < s.size(); i++) {
        map<char, int> mpp;
        for(int j = i; j < s.size(); j++) {
            mpp[s[j]]++;
            if(mpp.size() > k) break;
            maxlen = max(maxlen, j - i + 1);
        }
    }
    return maxlen;
}

int LongestSubstringWithKChar_optimal(string s, int k) {
    int maxlen = 0;
    int l = 0, r = 0;
    map<char, int> mpp;
    while(r < s.size()) {
        mpp[s[r]]++;
        while(mpp.size() > k) {
            mpp[s[l]]--;
            if(mpp[s[l]] == 0) {
                mpp.erase(s[l]);
            }
            l++;
        }
        maxlen = max(maxlen, r - l + 1);
        r++;
    }
    return maxlen;
}

int main() {
    string s = "aababbcaacc";
    int k = 2;
    cout << LongestSubstringWithKChar_optimal(s, k);
    return 0;
}