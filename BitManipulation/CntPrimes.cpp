#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int count(int f, int l) {
    int cnt = 0;
    for(int i = f; i <= l; i++) {
        bool prime = true;
        for(int j = 2; j <= sqrt(i); j++) {
            if(i % j == 0) {prime= false;
            break;}
        }
        if(prime) cnt++;

    }
    return cnt;
}

vector<int> cntPrimes(vector<vector<int>> queries) {
    vector<int> ans;
    for(int i = 0; i < queries.size(); i++) {
        ans.push_back(count(queries[i][0], queries[i][1]));
    }
    return ans;
}

int main() {
    vector<vector<int>> queries = {{2,5}, {4,7}};
    vector<int> ans = cntPrimes(queries);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}