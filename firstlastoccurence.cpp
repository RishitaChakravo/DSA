#include <iostream>
#include <vector>

using namespace std;

void first_occurence(vector<int> nums, int target) {
    int low = 0, high = nums.size() - 1;
    int first;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(nums[mid] == target){
            first = mid;
            high = mid - 1;
        } else if(nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << "First Occurence: " << first << endl;
}

void last_occurence(vector<int> nums, int target) {
    int low = 0, high = nums.size() - 1;
    int last;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(nums[mid] == target){
            last = mid;
            low = mid + 1;
        } else if(nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << "Last Occurence: " << last << endl;
}

int main() {
    vector<int> nums = {0, 3, 4, 13, 13, 13, 13, 45, 80};
    first_occurence(nums, 13);
    last_occurence(nums, 13);
    return 0;
}