#include <iostream>
#include <bits/stdc++.h>
#include<algorithm>

using namespace std;

bool checkIfOdd(int n) {
    return (n & 1) != 0;
}
int main() {
    int n = 10;
    cout << checkIfOdd(9);
    return 0;
}