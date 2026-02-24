#include<iostream>
#include <bits/stdc++.h>

using namespace std;

int countnicesubarray_brute(vector<int> nums, int k) {
    int numSubArray = 0;
    for(int i = 0; i < nums.size(); i++) {
        int odds = 0;
        for(int j = i; j < nums.size(); j++) {
            if(nums[j] % 2 != 0) odds++;
            if(odds > k) break;
            if(odds == k) numSubArray++;
        }
    }
    return numSubArray;
}

int atmost(vector<int> nums, int k) {
    if(k < 0) return 0;
    int atmostvalue = 0;
    int l= 0, r = 0, odds = 0;
    while(r < nums.size()) {
        if(nums[r] % 2 != 0) odds++;
        while(odds > k) {
            if(nums[l] % 2 != 0) odds--;
            l++;
        }
        atmostvalue += r - l + 1;
        r++;
    }
    return atmostvalue;
}

int countnicesubarray_optimal(vector<int> nums, int k) {
    return atmost(nums, k) - atmost(nums, k - 1);
}
int main() {
    vector<int> nums = {2,2,2,1,2,2,1,2,2,2};
    cout << countnicesubarray_optimal(nums, 2);
    return 0;
}