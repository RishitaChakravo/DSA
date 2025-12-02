#include <iostream>
#include <vector>
using namespace std;

int binaryapproach(vector<int> nums, int target) {
    int low = 0, high = nums.size() - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(nums[mid] == target) {
            return mid;
        }
        if(nums[low] == nums[mid] && nums[high] == nums[mid]) {
            low++;
            high--;
            continue;
        }
        if (nums[low] <= nums[mid]) {
            if(nums[low] <= target && nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else {
            if(nums[mid] < target && nums[high] >= target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main() {
    vector<int> nums = {2,2,2,2,3,2};
    cout << binaryapproach(nums, 3);
    return 0;
}