#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string minimumWindow(string s, string t){
    int minlength = INT_MAX;
    int sIndex;
    for(int i = 0; i < s.size(); i++) {
        map<char, int> mpp;
        int cnt = 0;
        for(int j = 0; j < t.size(); j++) mpp[t[j]]++;
        for(int j = i; j < s.size(); j++) {
            if(mpp[s[j]] > 0) cnt++;
            mpp[s[j]]--;
            if(cnt == t.size()){
                if(j - i + 1 < minlength) {
                    minlength = j - i + 1;
                    sIndex = i;
                    break;
                }
            }
        } 
    }
    return s.substr(sIndex, minlength);
}

string minWindow_optimal(string s, string t) {
    int minlength = INT_MAX, sIndex = -1;
    int l = 0, r = 0, cnt = 0;
    map<char, int> mpp;
    for(int i = 0; i < t.size(); i++) {
        mpp[t[i]]++;
    }
    while(r < s.size()) {
        if(mpp[s[r]] > 0) cnt++;
        mpp[s[r]]--;
        while(cnt == t.size()) {
            if(r - l + 1 < minlength) {
                minlength = r - l + 1;
                sIndex = l;
            }
            mpp[s[l]]++;
            if(mpp[s[l]] > 0) cnt--;
            l++;
        } 
        r++;
    }
    if (sIndex == -1) return "";
    return s.substr(sIndex, minlength);
}

int main() {
    string s = "ddaaabbca";
    string t = "abc";
    cout << minWindow_optimal(s, t);
    return 0;
}