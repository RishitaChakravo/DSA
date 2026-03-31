#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int myAtoi(string s) {
    int num = 0;
    int sign = 1;
    int i = 0;
    int n = s.size();

    while(i < n && s[i] == ' ') {
        i++;
    }

    if(i < n && (s[i] == '-' || s[i] == '+')) {
        if(s[i] == '-') sign = -1;
        i++;
    }

    while(i < n && s[i] >= '0' && s[i] <= '9') {
        int digit = s[i] - '0';

        if(num > (INT_MAX - digit) / 10) {
            return sign == 1 ? INT_MAX : INT_MIN;
        }

        num = num * 10 + digit;
        i++;
    }

    return num * sign;
}
int main() {
    string s = "   -0000154268 gfwigf";
    cout << myAtoi(s);
    return 0;
}