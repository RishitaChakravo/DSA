#include<iostream>
#include<vector>

using namespace std;

int binarysearch(vector<int> nums) {
    int n = nums.size();
    if(nums[0] != nums[1]) return 0;
    if(nums[n-1] != nums[n-2]) return n-1;
    int low = 1, high = nums.size() - 2;
    int ans = 0;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) return mid;
        
    }
    return ans;
}
int main() {
    vector<int> nums = {1,1,2,2,2,3,3,4,5,5,5,6,6};
    cout << binarysearch(nums);
    return 0;
}