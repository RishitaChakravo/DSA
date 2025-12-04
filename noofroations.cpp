#include <iostream>
#include <vector>
using namespace std;

int binaryapproach(vector<int> nums) {
    int minind = -1;
    int mini = INT16_MAX;
    int low = 0, high = nums.size() - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(nums[low] <= nums[high]) {
            if(nums[low] < mini) {
                minind = low;
                mini = nums[low];
            }
            break;
        }

        if(nums[low] <= nums[mid]) {
            if(mini > nums[low]) {
                minind = low;
                mini = nums[low];
            }
            low = mid + 1;
        } else {
            if(mini > nums[mid]) {
                mini = nums[mid];
                minind = mid;
            }
            high = mid - 1;
        }
    }
    return minind;
}

int main() {
    vector<int> nums = {6,5,4,3,2,1};
    cout << binaryapproach(nums);
    return 0;
}