#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void repeatandmissingnum(vector<int> nums) {
    vector<int> hashmpp(nums.size() + 1);
    for(int i = 0; i < nums.size(); i++) {
        hashmpp[nums[i]]++;
    }
    for(int i = 1; i < hashmpp.size(); i++) {
        if(hashmpp[i] == 0) {
            cout << "Missing: " << i <<endl;
        }
        if(hashmpp[i] >= 2) {
            cout << "Repeat: " << i <<endl;
        }
    }
}
vector<int> mathematicalsol(vector<int> nums) {
    int n = nums.size(), sumnums = 0, sumofsq=0;
    int sum = (n * (n + 1)) / 2;
    int sumsq = (n * (n+1) * (2*n + 1)) / 6;
    for(int i = 0; i < nums.size(); i++) {
        sumofsq += nums[i]*nums[i];
        sumnums += nums[i];
    }
    int x, y;
    int m1 = sum - sumnums;
    int m2 = sumsq - sumofsq;
    x = ((m2 / m1) + m1) / 2;
    y = x - m1;
    return {y, x};
}

int main() {
    vector<int> nums = {3, 1, 2, 5, 3};
    // repeatandmissingnum(nums);
    vector<int> result = mathematicalsol(nums);
    cout << "(" <<result[0] << ", " << result[1] << ")" << endl;
    return 0;
}