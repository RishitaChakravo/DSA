#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int kmissingnum_brute1(vector<int> arr, int k) {
    int j = 0;
    int i = 1;
    int num = -1;
    while(k > 0) {
        if(j < arr.size() && arr[j] == i) {
            j++;
        } else {
            num = i;
            k--;
        }
        i++;
    }
    return num;
}
int kmissingnum_brute2(vector<int> arr, int k) {
    int n = *max_element(arr.begin(), arr.end());
    for(int i = 0; i < n; i++) {
        if(arr[i] <= k) k++;
        else return k;
    }
    return -1;
}

int kmissingnum_binary(vector<int> arr, int k) {
    int low = 0;
    int high = arr.size() - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] - mid - 1 < k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    int n = low;
    low = high;
    high = n;
    return k + low + 1;
}
// arr[low] + (k - arr[low] + low + 1) = k + low + 1
int main() {
    vector<int> nums = {4,7,9,10};
    int k = 4;
    cout << kmissingnum_binary(nums, k);
    return 0;
}