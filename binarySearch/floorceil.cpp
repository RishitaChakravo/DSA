#include <iostream>
#include <vector>

using namespace std;

void floorceilofx(vector<int> nums, int target) {
    int low = 0, high = nums.size() - 1;
    int floor, ceil;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(nums[mid] > target) {
            high = mid - 1;
            ceil = mid;
        } else {
            low = mid + 1;
            floor = mid;
        }
    }
    cout << "Floor: " << nums[floor] << endl;
    cout << "Ceil: " << nums[ceil] << endl;
}

int main() {
    vector<int> nums = {1,4,5,6,7,8,12,13,14,16,19,25};
    floorceilofx(nums, 11);
    return 0;
}