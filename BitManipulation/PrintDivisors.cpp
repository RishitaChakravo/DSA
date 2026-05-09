#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<int> printDivisors(int N) {
    vector<int> ans;
    for(int i = 1; i <= sqrt(N); i++) {
        if(N % i == 0) ans.push_back(i);
        if(N % (N/i) == 0 && i != (N/i)) ans.push_back(N/i);
    }
    return ans;
}

int main() {
    vector<int> ans = printDivisors(16);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}