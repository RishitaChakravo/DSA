#include<iostream>
#include <bits/stdc++.h>

using namespace std;

int maxSubstring_brute(string s, int k) {
    int maxlen = 0;
    for(int i = 0; i < s.size(); i++) {
        unordered_map<int, int> mpp; 
        int maxf = 0, changes = 0;
        for(int j = i; j < s.size(); j++) {
            mpp[s[j] - 'A']++;
            maxf = max(maxf, mpp[s[j] - 'A']);
            changes = j - i + 1 - maxf;
            if(changes <= k)
                maxlen = max(maxlen, j - i + 1);
            else break;
        }
    }
    return maxlen;
}
int maxSubstring_better(string s, int k) {
    int maxlen = 0;
    int i = 0, j = 0, maxf = 0;
    vector<int> hash(26,0);
    while(j < s.size()) {
        hash[s[j] - 'A']++;
        maxf = max(maxf, hash[s[j] - 'A']);
        while((j - i + 1) - maxf > k) {
            maxf = 0;
            hash[s[i] - 'A']--;
            for(int k = 0; k < 26; k++) {
                maxf = max(maxf, hash[k]);
            }
            i++;
        }

        maxlen = max(maxlen, j - i + 1);
        j++;
    }
    return maxlen;
}
int maxSubstring_optimal(string s, int k) {
    int maxlen = 0;
    int i = 0, j = 0, maxf = 0;
    vector<int> hash(26,0);
    while(j < s.size()) {
        hash[s[j] - 'A']++;
        maxf = max(maxf, hash[s[j] - 'A']);
        int changes = (j - i + 1) - maxf;

        if (changes > k) {
            hash[s[i] - 'A']--;
            i++;
        }

        maxlen = max(maxlen, j - i + 1);
        j++;
    }
    return maxlen;
}
int main() {
    string s = "BAACAABBBAAA";
    int k = 2;
    cout << maxSubstring_better(s, k);
    return 0;
}