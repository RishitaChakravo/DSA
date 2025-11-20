#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int countnumberofSubarray(vector<int> nums, int k) {
    int cnt = 0;
    for(int i = 0; i < nums.size(); i++) {
        int xr = 0;
        for(int j = i; j < nums.size(); j++) {
            xr ^= nums[j];
            if(xr == k) cnt++;
        }
    }
    return cnt;
}

int countnumberofSubarrayOptimal(vector<int> nums, int k) {
    int xr = 0, cnt = 0;
    unordered_map<int, int> mpp;
    mpp[xr]++;
    for(int i = 0; i < nums.size(); i++) {
        xr ^= nums[i];
        if(mpp.find(xr ^ k) != mpp.end()) cnt += mpp[xr ^ k];
        mpp[xr]++;
    }
    return cnt;
}
int main() {
    vector<int> nums = {4, 2, 2, 6, 4};
    // cout << countnumberofSubarray(nums, 6);
    cout << countnumberofSubarrayOptimal(nums, 6);
    return 0;
}