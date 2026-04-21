#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int findsingle(vector<int> nums) {
    int ans = 0;
    for(int x : nums) {
        ans = ans ^ x;
    }
    return ans;
}

int main() {
    return 0;
}