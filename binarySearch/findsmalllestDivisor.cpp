#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool checkDivisors(vector<int> nums, int limit, int divisor) {
    float sum = 0;
    for(int i = 0; i < nums.size(); i++) {
        sum += (nums[i] + divisor - 1) / divisor;
    }

    if(sum <= limit) return true;
    return false;
}
// BRUTE
int smallestDivisor(vector<int> nums, int limit) {
    int max = *max_element(nums.begin(), nums.end());
    for(int i = 1; i <= max; i++) {
        if(checkDivisors(nums, limit, i)) return i;
    }
    return -1;
}
// BINARY
int smallestDivisor_binary(vector<int> nums, int limit) {
    int low = 1;
    int high = *max_element(nums.begin(), nums.end());
    int divisor = -1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(checkDivisors(nums, limit, mid)) {
            divisor = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return divisor;
}
int main(){
    vector<int> nums = {1,2,3,4,5};
    int limit = 8;
    cout << smallestDivisor_binary(nums, limit);
    return 0;
}