#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

float medianSortedArr_brute(vector<int> nums1, vector<int> nums2) {
    int n1 = nums1.size(),n2 = nums2.size();
    vector<int> nums(n1+n2);
    int i = 0, j = 0, k = 0;
    while(i < n1 && j < n2) {
        if(nums1[i] <= nums2[j]) {
            nums[k++] = nums1[i++];
        } else {
            nums[k++] = nums2[j++];
        }
    }

    while(i < n1) nums[k++] = nums1[i++];
    while(j < n2) nums[k++] = nums2[j++];

    int total = n1 + n2;

    if (total % 2 == 1) {
        return nums[total / 2];
    } else {
        return (nums[total / 2] + nums[(total / 2) - 1]) / 2.0;
    }
}

float medianSortedArr_binary(vector<int> nums1, vector<int> nums2) {
    if (nums1.size() > nums2.size())
        return medianSortedArr_binary(nums2, nums1);
    int n1 = nums1.size(),n2 = nums2.size();
    int total = n1 + n2;
    int low = 0;
    int high = n1 < n2 ? n1 : n2;
    int left = (n1+n2+1)/2;
    while(low <= high) {
        int mid1 = (low + high) / 2;
        int mid2 = left - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if(mid1 < n1) 
            r1 = nums1[mid1]; 
        if (mid1-1 >= 0) l1 = nums1[mid1-1];
        if(mid2 < n2) 
            r2 = nums2[mid2];
        if(mid2-1 >= 0)  l2 = nums2[mid2-1];
        if(l1 <= r2 && l2 <= r1) {
            if(total%2 == 1) return max(l1,l2);
            else return (max(l1,l2) + min(r1,r2)) / 2.0;
        } else if(l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }
    return -1;
}
int main() {
    vector<int> nums1 = {7,12,14,15};
    vector<int> nums2 = {1,2,3,4,9,11};
    cout << medianSortedArr_binary(nums1, nums2);
    return 0;
}