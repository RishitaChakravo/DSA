#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int kokobanana_brute(vector<int> arr, int h) {
    int k = 1;
    int max = *max_element(arr.begin(), arr.end());
    for(;k <= max; k++) {
        int sum = 0;
        for(int i = 0; i < arr.size(); i++) {
            int temp = arr[i];
            while(temp > k) {
                temp = temp - k;
                sum++;
            } 
            if(temp <= k) {
                sum++;
            }
        }
        if(sum <= h) return k;
    }
    return -1;
}

int kokobanana_better(vector<int> arr, int h) {
    int k = 1;
    int max = *max_element(arr.begin(), arr.end());
    for(;k <= max; k++) {
        int sum = 0;
        for(int i = 0; i < arr.size(); i++) {
            int temp = arr[i];
            // while(temp > k) {
            //     temp = temp - k;
            //     sum++;
            // } 
            // if(temp <= k) {
            //     sum++;
            // }
            sum += (temp + k - 1) / k;

            if(sum > h) break;
        }
        if(sum <= h) return k;
    }
    return -1;
}

int kokobanana_binary(vector<int> arr, int h) {
    int low = 1;
    int high = *max_element(arr.begin(), arr.end());
    int mid;
    while(low <= high) {
        mid = (low + high) / 2;
        int sum = 0;
        for(int i = 0; i < arr.size(); i++) {
            int temp = arr[i];
            sum += (temp + mid - 1) / mid;
            if(sum > h) break;
        }

        if(sum <= h) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int main() {
    vector<int> nums = {7,15,6,3};
    int h = 8;
    // cout << kokobanana_brute(nums, h) <<endl;
    // cout << kokobanana_better(nums, h) << endl;
    cout << kokobanana_binary(nums, h) << endl;
    return 0;
}