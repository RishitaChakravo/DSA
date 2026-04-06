#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int sumofBeautyPoints(string s) {
    int sum = 0;
    for(int i = 0; i < s.size(); i++) {
        unordered_map<char, int> freq;
        for(int j = i; j < s.size(); j++) {
            freq[s[j]]++;

            int maxi = INT_MIN;
            int mini = INT_MAX;

            for(auto it : freq) {
                mini = min(mini, it.second);
                maxi = max(maxi, it.second);
            }

            sum += maxi-mini;
        }
    }
    return sum;
}
int main(){
    string s = "aabcbaa";
    cout << sumofBeautyPoints(s);
    return 0;
}