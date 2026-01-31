#include<iostream>
#include<vector>

using namespace std;

int binarysearch(vector<int> nums, int n) {
    if(n == 1) return 0;
    if(nums[0] > nums[1]) return 0;
    if(nums[n - 1] > nums[n-2]) return n-1;

    int low = 1, high = n-2;
    while(low <= high) {
        int mid = (low + high) / 2;

        if(nums[mid] > nums[mid -1] && nums[mid] > nums[mid + 1]) return mid;
        else {
            if(nums[mid] > nums[mid - 1]) low = mid + 1;
            else high = mid - 1;
        }
    }
}
int main() {
    vector<int> nums = {1,5,1,2,1};
    cout << binarysearch(nums, 5);
    return 0;
}