#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int median2Darr_brute(vector<vector<int>> nums) {
    int n = nums.size();
    int m = nums[0].size();
    vector<int> new_arr(n*m);
    int k = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            new_arr[k++] = nums[i][j];
        }
    }
    sort(new_arr.begin(), new_arr.end());

    return new_arr[(n*m)/2];
}
int main() {
    vector<vector<int>> nums = {{1,5,7,9,11},{2,3,4,5,10},{9,10,12,14,16}};
    cout << median2Darr_brute(nums);
    return 0;
}