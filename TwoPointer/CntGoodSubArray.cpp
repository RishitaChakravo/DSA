#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int cntGoodSubArray_brute(vector<int> nums, int k) {
    int maxSubArray = 0;
    for(int i = 0; i < nums.size(); i++) {
        map<int, int> mpp;
        for(int j = i; j < nums.size(); j++) {
            mpp[nums[j]]++;
            if(mpp.size() > k) break;
            if(mpp.size() == k) maxSubArray++;
        }
    }
    return maxSubArray;
}

int atmost(vector<int> nums, int k) {
    int maxvalue = 0;
    int r = 0, l = 0, n = nums.size(), d = 0;
    vector<int> v(n+1, 0);
    while(r < nums.size()) {
        if(v[nums[r]] == 0) {
            d++;
        }
        v[nums[r]]++;
        while(d > k) {
            v[nums[l]]--;
            if(v[nums[l]] == 0) d--;
            l++;
        }
        maxvalue += r - l + 1;
        r++;
    } 
    return maxvalue;
}

int cntGoodSubArray_optimal(vector<int> nums, int k) {
    return atmost(nums, k) - atmost(nums, k - 1);
}

int main() {
    vector<int> nums = {1,2,1,2,3};
    int k = 2;
    cout << cntGoodSubArray_optimal(nums, k);
    return 0;
}