#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int cntbitstoflip(int a, int b) {
    int ans = 0;
    while(a >= 1 && b >= 1) {
        if((a & 1) != (b & 1)) ans++;
        a >>= 1;
        b >>= 1;
    }

    while(a >= 1) {
        if((a & 1) != 0) ans++;
        a >>= 1;
    }

    while(b >= 1) {
        if((b & 1) != 0) ans++;
        b >>= 1;
    }
    return ans;
}

int cntbitstoflip2(int a, int b) {
    int ans = a ^ b, cnt = 0;
    while(ans >= 1) {
        if(ans & 1 == 1) cnt++;
        ans >>= 1;
    }
    return cnt;
}

int main() {
    cout << cntbitstoflip2(4, 3);
    return 0;
}