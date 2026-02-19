#include<iostream>
#include <bits/stdc++.h>

using namespace std;

int maxfruits_brute(vector<int> nums) {
    int maxfruits = 0;
    for(int i = 0; i < nums.size(); i++) {
        int fruits = 0;
        int bask1 = nums[i], bask2 = -1;
        for(int j = i; j < nums.size(); j++) {
            if(bask2 == -1 && nums[j]!=bask1) bask2 = nums[j];
            if(nums[j]!= bask1 && nums[j]!=bask2) break;
            fruits++;
        }
        maxfruits = max(maxfruits, fruits);
    }
    return maxfruits;
}

int maxfruits_optimal(vector<int> nums) {
    int maxfruits = 0;
    int l = 0, r = 0;
    unordered_map<int, int> mpp;
    while(r < nums.size()){
        mpp[nums[r]]++;
        while(mpp.size() > 2) {
            mpp[nums[l]]--;
            if(mpp[nums[l]] == 0)
                mpp.erase(nums[l]);
            l++;
        }
        maxfruits = max(maxfruits, r - l + 1);
        r++;
    }
    return maxfruits;
}

int main() {
    vector<int> fruits = {1, 2, 1};
    cout <<  maxfruits_optimal(fruits);
    return 0;
}