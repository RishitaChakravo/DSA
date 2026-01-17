#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>

using namespace std;

int max1row(vector<vector<int>> nums) {
    int n = nums.size();
    int maxsum = 0;
    int maxrow = -1;
    for(int i = 0; i < n; i++) {
        int sum = accumulate(nums[i].begin(), nums[i].end(), 0);
        if(sum > maxsum) {
            maxsum = sum;
            maxrow = i;
        }
    }
    return maxrow;
}

int max1row_optimal(vector<vector<int>> nums) {
    int n = nums.size();
    int m = nums[0].size();

    int maxone = 0;
    int maxrow = -1;
    
    for(int i = 0; i < n; i++) {
        int low = 0;
        int high = m - 1;
        int firstone = m;

        while(low <= high) {
            int mid = (low + high) / 2;
            
            if(nums[i][mid] == 1) {
                firstone = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        int ones = m - firstone;
        if(ones > maxone) {
            maxone = ones;
            maxrow = i;
        }
    }
    return maxrow;
}

int main() {
    vector<vector<int>> nums = {{0,0,0}, {0,0,1}, {0,1,1}};
    cout << max1row_optimal(nums);
    return 0;
}