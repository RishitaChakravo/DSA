#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// BRUTE
vector<vector<int>> threesum1(vector<int> nums) {
    set<vector<int>> st;
    for(int i = 0; i < nums.size(); i++) {
        for(int j = i + 1; j < nums.size(); j++) {
            for(int k = j + 1; k < nums.size(); k++) {
                if(nums[i] + nums[j] + nums[k] == 0){
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> result(st.begin(), st.end());
    return result;
}

// BETTER
vector<vector<int>> threesum2(vector<int> nums) {
    set<vector<int>> st;
    for(int i = 0; i < nums.size(); i++) {
        set<int> mpp;
        for(int j = i + 1; j < nums.size(); j++) {
            int third = -(nums[i] + nums[j]);
            if(mpp.find(third) != mpp.end()){
                vector<int> temp = {nums[i], nums[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            mpp.insert(nums[j]);
        }
    }
    vector<vector<int>> result(st.begin(), st.end());
    return result;
}

// OPTIMAL
// in every pass i remains constant and k moves when sum is greater than zero j moves when sum is less than zero
vector<vector<int>> threesum3(vector<int> nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); i++) {
        if(i > 0 && nums[i] == nums[i - 1]) continue;
        int j = i + 1;
        int k = nums.size() - 1;
        while(j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if(sum < 0) j++;
            else if(sum > 0) k--;
            else{
                vector<int> temp = {nums[i], nums[j], nums[k]};
                result.push_back(temp);
                j++;
                k--;
                while(j < k && nums[j] == nums[j - 1]) j++;
                while(j < k && nums[k] == nums[k + 1]) k--;
            }
        }
    }
    return result;
}

void print(vector<vector<int>> vec) {
    for(int i = 0; i < vec.size(); i++) {
        for(int j = 0; j < vec[i].size(); j++) {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<int> nums = {-1,0,1,2,-1,-4};
    // vector<vector<int>> result = threesum1(nums); // 3.082 sec
    // vector<vector<int>> result = threesum2(nums); // 1.975 sec
    vector<vector<int>> result = threesum3(nums); // 1.89 sec
    print(result);
    return 0;
}