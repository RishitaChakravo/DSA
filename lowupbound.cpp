#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int implementLowerBound(vector<int> nums, int n) {
    int low = 0, high = nums.size() - 1;
    int ans = nums.size() - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(nums[mid] == n) {
            ans = mid;
            break;
        } else if(nums[mid] > n) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int implementupperbound(vector<int> nums, int n) {
    int low = 0, high = nums.size() - 1;
    int ans = nums.size() - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(nums[mid] > n) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {1, 4, 5, 9, 11, 18, 19, 20, 25, 64};
    auto it = lower_bound(nums.begin(), nums.end(), 6); 
    cout << implementupperbound(nums, 5);
    return 0;
}