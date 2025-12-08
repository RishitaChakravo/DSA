#include <iostream>
#include <cmath>

using namespace std;

int NthRootBrute(int n, int m) {
    int ans = 1;
    for(int i = 0; i < m; i++) {
        long long val = pow(i, n);
        if(val == m) return i;
        else
            break;
    }
    return ans;    
}

int NthRootBinary(int n, int m) {
    int ans = -1;
    int low = 1, high = m;
    while(low <= high) {
        int mid = (low + high) / 2;
        long long val = pow(mid, n);

        if(val == m) return mid;
        if(val < m) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    // cout << "Brute: "<< NthRootBrute(3, 10000) << endl;
    cout << "Optimal: "<< NthRootBinary(3, 96) << endl;
    return 0;
}