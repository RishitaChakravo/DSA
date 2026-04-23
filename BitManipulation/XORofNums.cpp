#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int xornums(int l, int r) {
    int ans = 0;
    for(int i = l; i <= r; i++) {
        ans ^= i;
    }
    return ans;
}

int xornums2(int l, int r) {
    int ans = 0;
    if((l - 1) % 4 == 0) ans ^= l-1;
    if((l - 1) % 4 == 1) ans ^= 1;
    if((l - 1) % 4 == 2) ans ^= l;
    if((l - 1) % 4 == 3) ans ^= 0;

    if(r % 4 == 0) ans ^= r;
    if(r % 4 == 1) ans ^= 1;
    if(r % 4 == 2) ans ^= r + 1;
    if(r % 4 == 3) ans ^= 0;

    return ans;
}

int main() {
    int l = 3, r = 5;
    cout << xornums2(l, r);
    return 0;
}