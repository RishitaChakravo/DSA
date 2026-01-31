#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int longestSubarraySumKBetter(vector<int> nums, int k) {
    unordered_map<int, int> hash;
    int sum = 0, len = 0;
    for(int i = 0; i < nums.size(); i++) {
        sum += nums[i];

        if(sum == k) 
            len = i + 1;
        
        if(hash.find(sum - k) != hash.end()){
            len = max(len, i - hash[sum - k]);
        }

        if(hash.find(sum) == hash.end()) {
            hash[sum] = i;
        }
    }
    return len;
}

int longestSubarraySumKBest(vector<int> nums, int k) {
    int i = 0, j = 0, sum = 0, len = 0;
    while(j < nums.size()) {
        sum += nums[j];
        while (sum > k && i <= j) {
            sum -= nums[i];
            i++;
        }

        if (sum == k) {
            len = max(len, j - i + 1);
        }

        j++;
    }
    return len;
}

int main() {
    vector<int> nums = {2,1,4,3,0,1,1,1,0,0,5};
    cout << longestSubarraySumKBest(nums, 3);
    return 0;
}