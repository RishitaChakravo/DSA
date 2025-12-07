#include <iostream>
#include <vector>
using namespace std;

int rootBinary(int n) {
    // finding root using binary search
    int low = 1, high = n;
    int ans = 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(mid * mid == n) return mid;

        if(mid * mid > n) high = mid - 1;
        else {
            ans = mid;
            low = mid + 1;
        }
    }
    return ans;
}

int rootbrute(int n) {
    int ans = 1;
    for(int i = 1; i <= n; i++) {
        if(i * i <= n) {
            ans = i;
        } else {
            break;
        }
    }
    return ans;
}
int main() {
    cout << rootBinary(25000);
    return 0;
}