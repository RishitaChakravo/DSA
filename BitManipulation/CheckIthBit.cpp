#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool checkIthBit_brute(int n, int i) {
    string num = "";
    while(n != 1) {
        if(n % 2 == 1) num += '1';
        else num += '0';
        n = n/2;
    }
    num += '1';
    int s = num.size();
    i = s - i - 1;
    if (num[i] == '1') return true;
    else return false; 
}

bool checkIthBit_optimal1(int n, int i) {
    return (n & (1 << i)) != 0;
}

bool checkIthBit_optimal2(int n, int i) {
    return (n >> i) & 1 == 1;
}

int main() {
    int n = 5;
    int i = 0;
    cout << checkIthBit_optimal2(n, i)<<endl;

    // int a = 5, b = 6;
    // a = a ^ b;
    // b = a ^ b;
    // a = a ^ b;
    // cout << a <<" "<< b;
    return 0;
}