#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int cntSubStrings(string s, int k) {
    int cnt = 0;
    unordered_map<char, int> uniq_c;
    int first = 0, last = 0;
    while(last < s.size()) {
        uniq_c[s[last]]++;
        while(uniq_c.size() > k) {
            uniq_c[s[first]]--;
            if(uniq_c[s[first]] == 0) uniq_c.erase(s[first]);
            first++;
        }
        cnt += (last - first + 1);
        last++;
    }
    return cnt;
}

int toCntSubstr(string s, int k) {
    return cntSubStrings(s, k) - cntSubStrings(s, k - 1);
}
int main() {
    string s = "pqpqs";
    cout << toCntSubstr(s, 2);
    return 0;
}