#include <iostream>
#include <bits/stdc++.h>
#include<algorithm>

using namespace std;

string dec2bin(int x) {
    string res = "";
    while(x != 1) {
        if(x % 2 == 1) res += '1';
        else res += '0';
        x = x / 2;
    }
    res += '1';
    reverse(res.begin(), res.end());
    return res;
}

int bin2dec(string s) {
    int sum = 0, n = s.size() - 1;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '1') sum += pow(2, n);
        
        n--;
    }
    return sum;
}

int main() {
    int x = 15;
    string s = "1111";
    cout << dec2bin(x) << endl;
    cout << bin2dec(s) << endl;
    return 0;
}