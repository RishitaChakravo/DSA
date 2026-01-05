#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int sumweights(vector<int> nums) {
    int sum = 0;
    for(int i = 0; i < nums.size(); i++) {
        sum += nums[i];
    }
    return sum;
}

int min_capacity_ship_brute(vector<int> weights, int days) {
    int maxel = *max_element(weights.begin(), weights.end());
    int maxweight = accumulate(weights.begin(), weights.end(), 0);

    for(int i = maxel; i <= maxweight; i++) {
        int d = 1;
        int load = 0;

        for(int w : weights) {
            if(load + w > i) {
                d++;
                load = w;
            } else {
                load += w;
            }
        }
        if(d <= days) return i;
    }
    return -1;
}
int min_capacity_ship_binary(vector<int> weights, int days) {
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);
    int cap;
    while(low <= high) {
        cap = (low + high) / 2;
        int d = 1;
        int load = 0;

        for(int w : weights) {
            if(load + w > cap) {
                d++;
                load = w;
            } else {
                load += w;
            }
        }

        if(d <= days) {
            high = cap - 1;
        } else {
            low = cap + 1;
        }
    }
    return low;
}    
int main() {
    vector<int> weights = {5, 4, 5, 2, 3, 4, 5, 6};
    int days = 5;
    cout << min_capacity_ship_binary(weights, days);
    return 0;
}