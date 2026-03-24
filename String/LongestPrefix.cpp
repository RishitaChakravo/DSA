#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string longestPrefix(vector<string> words) {
    if(words.empty()) return "";
    string prefix = words[0];
    for(int i = 1; i < words.size(); i++) {
        int j = 0;
        while(j < prefix.size() && j < words[i].size() && prefix[j] == words[i][j]) {
            j++;
        }
        if(prefix == "") return "";
        prefix = prefix.substr(0, j);
    }
    return prefix;
}
int main() {
    vector<string> words = {"apple", "banana", "grape"};
    cout << longestPrefix(words);
    return 0;
}