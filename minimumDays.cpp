#include <iostream>
#include <vector>
#include <map>
#define N 100
using namespace std;

// minimum number of days to make m bouquets each with k roses
int bouquets(vector<int> arr, int k, int m) {
    if(k * m > arr.size()) return -1;
    map<int, vector<vector<int>>> bouquet;
    for(int i = 0; i < arr.size(); i++) {
        int maxi = INT16_MIN;
        vector<int> v;
        bool flag = false;
        for(int j = i; j < i + k && j < arr.size(); j++) {
            if(maxi < arr[j]) {
                flag = true;
                break;
            }
            maxi = max(maxi, arr[j]);
            v.push_back(arr[j]);
        }
        if(!flag) bouquet[maxi].push_back(v);
    }
    auto it = bouquet.begin();
    for(int i = 1; i < m; i++) {
        it++;
    }
    return it->first;
}
// only checks of flowers are adjacent 🥲 we also need it to check if the elements are either equal to or smaller than the prev element

int main() {
    vector<int> nums = {3, 1, 3, 1, 3};
    int m = 1, k = 3;
    cout << bouquets(nums, k, m);
    return 0;
}