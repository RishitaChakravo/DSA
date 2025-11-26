#include <iostream>
#include <vector>

using namespace std;
// OPTIMAL
// Observation: through observation its visible that even negatives result in no problems but for odd 
// negatives we either take the prefix prod or suffix prod...then if array has zeroes then the subarray
// in between the zeroes are our subarrays as the zero will result in prod of zero..
int maxprodsubarray(vector<int> nums) {
    int maxprod = INT8_MIN;
    int pref = 1;
    int suff = 1;
    for(int i = 0; i < nums.size(); i++) {
        if(pref == 0) pref = 1;
        if(suff == 0) suff = 1;

        pref *= nums[i];
        suff *= nums[nums.size() - i - 1];

        maxprod = max(maxprod, max(pref, suff));
    }
    return maxprod;
}

int main() {
    vector<int> nums = {2, 3, -2, 4};
    cout << maxprodsubarray(nums);
    return 0;
}