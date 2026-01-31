#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> searchTarget(int target, vector<vector<int>> nums) {
    if (nums.empty() || nums[0].empty()) return {-1, -1};

    vector<int> ind = {-1, -1};
    int n = nums.size();
    int m = nums[0].size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(nums[i][j] == target) {
                ind[0] = i;
                ind[1] = j;
                break;
            }
        }
    }
    return ind;
}

// this becomes the optimal solution if the condition of last element of one row lesser than first element of next row is removed
vector<int> searchTarget_better(int target, vector<vector<int>> nums) {
    if (nums.empty() || nums[0].empty()) return {-1, -1};

    vector<int> ind = {-1, -1};
    int n = nums.size();
    int m = nums[0].size();
    int i = 0, j = m - 1;

    while(i < n && j >= 0){
        if(target == nums[i][j]) {
            ind[0] = i;
            ind[1] = j;
            break;
        } else if(target > nums[i][j]) {
            i++;
        } else {
            j--;
        }
    }
    return ind;
}

// this case doesnt if the condition is removed
vector<int> searchTarget_optimal(int target, vector<vector<int>>& nums) {
    if (nums.empty() || nums[0].empty())
        return {-1, -1};

    int n = nums.size();
    int m = nums[0].size();

    int low = 0, high = n - 1;
    int row = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (target >= nums[mid][0] && target <= nums[mid][m - 1]) {
            row = mid;
            break;
        } else if (target < nums[mid][0]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if (row == -1) return {-1, -1};

    int l = 0, r = m - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (nums[row][mid] == target)
            return {row, mid};
        else if (nums[row][mid] < target)
            l = mid + 1;
        else
            r = mid - 1;
    }

    return {-1, -1};
}



int main() {
    vector<vector<int>> nums = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    vector<int> result = searchTarget_optimal(8, nums);
    cout << "(" << result[0] << "," << result[1] <<")";
    return 0;
}