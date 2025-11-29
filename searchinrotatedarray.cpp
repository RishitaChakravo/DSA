#include <iostream>
#include <vector> 
using namespace std;
// Brute Force
void linearsearchapproach(vector<int> nums, int target) {
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] == target) break;
    }
}

int binarysearchapproach(vector<int> nums, int target) {
    int low = 0, high = nums.size() - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(nums[mid] == target) return mid + 1;
        
        if(nums[low] > nums[mid]) {
            if(nums[mid] < target && nums[high] > target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        } else {
            if(nums[mid] > target && nums[low] <= target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
    }
    return -1;
}
int main() {
    vector<int> nums = {6,7,0,1,2,3,4,5};
    int target = 1;
    cout << binarysearchapproach(nums, target);
    return 0;
}