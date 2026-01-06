#include<iostream>
#include<numeric>
#include<vector>
#include<algorithm>

using namespace std;

int splitarray_sum_brute(vector<int>& nums, int k) {
    int splitsum = *max_element(nums.begin(), nums.end());
    int maxsum = accumulate(nums.begin(), nums.end(), 0);

    for(; splitsum <= maxsum; splitsum++) {
        int sum = 0;
        int subarray = 1;
        for(int a : nums) {
            if(sum + a > splitsum) {
                subarray++;
                sum = a;
            } else sum += a;
        }
        if(subarray <= k) return splitsum;
    }
    return -1;
}

int splitarray_sum_binary(vector<int>& nums, int k) {
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);

    while(low <= high) {
        int splitsum = (low + high) / 2;
        int sum = 0;
        int subarray = 1;

        for(int a : nums) {
            if(sum + a > splitsum) {
                subarray++;
                sum = a;
            } else sum += a;
        }

        if(subarray <= k)
            high = splitsum - 1;
        else
            low = splitsum + 1;
    }
    return low;
}

int main() {
    vector<int> nums = {1,2,3,4,5};
    int k = 3;
    cout << splitarray_sum_binary(nums, k);
    return 0;
}