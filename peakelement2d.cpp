#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> peakelement_brute(vector<vector<int>> nums) {
    vector<vector<int>> ans;
    int n = nums.size();
    int m = nums[0].size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int up = (i > 0) ? nums[i-1][j] : -1;
            int left = (j > 0) ? nums[i][j-1] : -1;
            int down = (i < n-1) ? nums[i+1][j] : -1;
            int right = (j < m-1) ? nums[i][j+1] : -1;
            
            if (nums[i][j] > up &&
                nums[i][j] > down &&
                nums[i][j] > left &&
                nums[i][j] > right) {

                ans.push_back({i,j}); 
            }
        }
    }
    return ans;
}

vector<int> peakelement_optimal(vector<vector<int>> nums) {
    int n = nums.size();
    int m = nums[0].size();
    int low = 0;
    int high = n - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        int maxel = nums[mid][0];
        int ind = 0;
        for(int j = 1; j < m; j++) {
            if(nums[mid][j] > maxel) {
                maxel = nums[mid][j];
                ind = j;
            }
        }

        int up = mid > 0 ? nums[mid - 1][ind] : -1;
        int down = mid < n-1 ? nums[mid + 1][ind] : -1;

        if (nums[mid][ind] > up && nums[mid][ind] > down) {
            return {mid, ind};
        }
        else if(nums[mid][ind] < up) high = mid - 1;
        else low = mid- 1;
    }
    return {-1, -1};
}
int main(){
    vector<vector<int>> nums= {{10,20,15},{21,30,14}, {7,16,32}};
    vector<int> ans = peakelement_optimal(nums);
    cout << "[" << ans[0] << "," << ans[1] << "]";
    return 0;
}