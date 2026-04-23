#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<int> singlenums3(vector<int> nums) {
    int n = 0;
    for(int i = 0; i <nums.size(); i++) n^=nums[i];
    int rightMost = (n & n - 1) ^ n, b1 = 0, b2 = 0;
    for(int i = 0; i <nums.size(); i++) { 
        if((nums[i] & rightMost) == 0) b1 ^= nums[i];
        else b2 ^= nums[i];
    }
    return {b1, b2};
}

int main() {
    // brute - use hashing
    vector<int> ans;
    vector<int> nums = {1,2,2,1,3,5};
    ans = singlenums3(nums);

    cout<<ans[0] <<" "<< ans[1];
    return 0;
}