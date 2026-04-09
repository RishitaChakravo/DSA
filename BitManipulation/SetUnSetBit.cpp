#include <iostream>
#include <bits/stdc++.h>
#include<algorithm>

using namespace std;

int setIthBit1(int n, int i) {
    if (((n >> i) & 1) == 0) return pow(2, i) + n;
    else return n;
}

int setIthBit2(int n, int i) {
    return n | 1 << i;
}

int clearBit(int n, int i) {
    if(((n >> i) & 1) != 0) return abs(n - pow(2, i));
    else return n;
}

int main() {
    int n = 15;
    int i = 1;
    cout << clearBit(n, i);
    return 0;
}