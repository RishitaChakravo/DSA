#include<iostream>
#include <bits/stdc++.h>

using namespace std;

int numofsubarr_binarysum_brute(vector<int> nums, int goal) {
    int subArrays = 0;

    for(int i = 0; i < nums.size(); i++) {
        int sum = 0;

        for(int j = i; j < nums.size(); j++) {
            sum += nums[j];

            if(sum > goal) break;      

            if(sum == goal) 
                subArrays++;
        }
    }
    return subArrays;
}

int maxsubarray(vector<int> nums, int goal) {
    if(goal < 0) return 0;
    int cnt = 0;
    int l = 0, r = 0, sum = 0;
    while(r < nums.size()) {
        sum += nums[r];
        while(sum > goal) {
            sum -= nums[l];
            l++;
        }
        cnt += r - l + 1;
        r++;
    }
    return cnt;
}
int numofsubarr_binarysum_optimal(vector<int> nums, int goal) {
    return maxsubarray(nums, goal) - maxsubarray(nums, goal - 1);
}
int main() {
    vector<int> nums = {1,0,0,1,1,0};
    int goal = 2;
    cout << numofsubarr_binarysum_optimal(nums, goal);
    return 0;
}