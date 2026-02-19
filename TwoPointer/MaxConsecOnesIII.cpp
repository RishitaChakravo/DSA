#include<iostream>
#include <bits/stdc++.h>

using namespace std;

int maxConsecOnes_brute(vector<int> nums, int k) {
    int maxones = 0;
    for(int i = 0; i < nums.size(); i++) {
        int zeroes = 0;
        for(int j = i; j < nums.size(); j++) {
            if(nums[j] == 0) {
                zeroes++;
            }
            if(zeroes > k) break;
            maxones = max(maxones, j - i + 1);
        }
    }
    return maxones;
}

int maxConsecOnes_optimal(vector<int> nums, int k) {
    int maxones = 0, zeroes = 0;
    int i = 0, j = 0;
    while(j < nums.size()) {
        if(nums[j] == 0) zeroes++;
        while(zeroes > k) {
            if(nums[i] == 0) zeroes--;
            i++;
        }
        maxones = max(maxones, j - i + 1);
        j++;
    }
    return maxones;
}
int main(){
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    cout << maxConsecOnes_optimal(nums, 2);
    return 0;
}