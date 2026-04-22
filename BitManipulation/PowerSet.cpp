#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> powerSet(vector<int> nums) {
    int n = nums.size();
    vector<vector<int>> answer;
    for(int i = 0; i < (1 << n); i++) {
        vector<int> subset;
        int temp = i;
        for(int j = 0; j < n; j++) {
            if((temp & 1)== 1) {
                subset.push_back(nums[j]);
            }
            temp >>=1;
        }
        answer.push_back(subset);
    }
    return answer;
}

int main() {
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans = powerSet(nums);
    for(int i = 0; i < (1 << nums.size()); i++) {
        cout << "[ ";
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}