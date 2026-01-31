#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int binaryapproach(vector<int>nums) {
    int low = 0, high = nums.size() - 1;
    int mini = INT8_MAX;
    while(low <= high) {
        int mid = (low + high) / 2;
        
        if(nums[low] <= nums[high]) {
            mini = min(mini, nums[low]);
            break;
        }
        
        if(nums[low] <= nums[mid]) {
            mini = min(mini, nums[low]);
            low = mid + 1;
        } else {
            mini = min(mini, nums[mid]);
            high = mid - 1 ;
        }
    }
    return mini;
}
int main() {
    vector<int> nums = {7,6,5,4,3,2,1};
    cout << binaryapproach(nums);
    return 0;
}