#include <iostream>
#include <vector>

using namespace std;
int cnt = 0;

// BETTER - using mergesort
void merge(vector<int>&nums, int l, int mid, int h) {
    int n1 = mid - l + 1, n2 = h - mid;
    vector<int> lft(mid - l + 1);
    vector<int> rgt(h - mid);
    for(int i = 0; i < n1; i++) 
        lft[i] = nums[l+i];
    for(int i = 0; i < n2; i++) {
        rgt[i] = nums[mid + i + 1];
    }
    int j = 0;
    for(int i = 0; i < n1; i++) {
        while(j < n2 && (long long)lft[i] > 2LL*rgt[j])
            j++;
        cnt += j;
    } 
    int i = 0, k = l; 
    j = 0;
    while(i < n1 && j < n2) {

        if(lft[i] < rgt[j]) {
            nums[k++] = lft[i++];
        } else{
            nums[k++] = rgt[j++];
        }
    }

    while(i < n1) nums[k++] = lft[i++];
    while(j < n2) nums[k++] = rgt[j++];
}

void mergesort(vector<int>&nums, int l, int h){
    if(l >= h) return;
    int mid = (l + h) / 2;
    mergesort(nums, l, mid);
    mergesort(nums, mid + 1, h);

    merge(nums, l, mid, h);
}

int reversepair(vector<int> nums) {
    int cnt = 0;
    for(int i = 0; i < nums.size() - 1; i++) {
        for(int j = i + 1; j < nums.size(); j++) {
            if(nums[i] > (2*nums[j])) cnt++;
        }
    }
    return cnt;
}

int main() {
    vector<int> nums = {1,3,2,3,1};
    // cout << reversepair(nums);
    mergesort(nums, 0, 4);
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    cout << cnt;
    return 0;
}