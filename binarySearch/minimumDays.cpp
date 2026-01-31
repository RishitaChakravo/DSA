#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <algorithm>
#define N 100
using namespace std;

// minimum number of days to make m bouquets each with k roses
// this does work for a number of cases but not for all cases
// here the number of days arent taken into consideration and this overall just takes care of certain test cases storing vectors which is not resouce effective
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
// BRUTE FORCE
int mindays_brute(vector<int> arr, int k, int m) {
    int bloomsDay = INT_MAX;
    for(int i = 0; i < arr.size(); i++) {
        int D = arr[i];
        int bouquet = 0;
        int flowers = 0;

        for(int j = 0; j < arr.size(); j++) {
            if(arr[j] <= D) {
                flowers++;
                if(flowers == k) {
                    bouquet++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
        }

        if(bouquet >= m) {
            bloomsDay = min(bloomsDay, D);
        }
    }
    return (bloomsDay == INT_MAX ? -1 : bloomsDay);
}

int mindays_binary(vector<int> arr, int k, int m) {
    if ((long long)m * k > arr.size()) return -1;
    int bloomsday = -1;
    int low = *min_element(arr.begin(), arr.end());
    int high = *max_element(arr.begin(), arr.end());

    while(low <= high) {
        int mid = (low + high) / 2;
        int bouquets = 0;
        int flowers = 0;
        int D = mid;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] <= D) {
                flowers++;
                if(flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
        }

        if(bouquets >= m) {
            bloomsday = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return bloomsday;
}
int main() {
    vector<int> nums = {7,7,7,7,7,13,11,12,7};
    int m = 2, k = 3;
    cout << mindays_binary(nums, k, m);
    return 0;
}