#include <iostream>
#include <bits/stdc++.h>
#include<algorithm>

using namespace std;

int Divide2Int_brute(int dividend, int divisor) {
    int sign_dd = 1, sign_dv = 1;
    int cnt = 0;
    if(dividend < 0) {
        sign_dd = -1;
        dividend *= -1;
    }
    if(divisor < 0) {
        sign_dv = -1;
        divisor *= -1;
    }
    while(dividend > divisor) {
        dividend = dividend - divisor;
        cnt++;
    }

    return cnt * sign_dd * sign_dv;
}

int Divide2Int_optimal(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) return INT_MAX;
    long long ans = 0;
    long long dvd = abs((long long)dividend);
    long long dvs = abs((long long) divisor);
    while(dvd >= dvs) {
        long long temp = dvs;
        int p = 1;
        while((temp << 1) <= dvd) {
            temp = temp << 1;
            p = p << 1;
        }
        dvd -= temp;
        ans += p;
    }

    if((dividend < 0) ^ (divisor < 0)) ans = -ans;
    return ans;
}
int main(){
    cout << Divide2Int_optimal(10, 3);
    return 0;
} 