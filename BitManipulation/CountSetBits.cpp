#include <iostream>
#include <bits/stdc++.h>
#include<algorithm>

using namespace std;

int CountSetBits(int n) {
    int cnt = 0;
    while(n>0) {
        if((n & 1) != 0) cnt++;
        n >>= 1;
    }
    return cnt;
}
int main() {
    cout << CountSetBits(0);
    return 0;
}