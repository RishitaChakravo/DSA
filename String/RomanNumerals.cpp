#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int roman(string s) {
    int sum = 0, checker = 0;
    int I = 1, V = 5, X = 10, L = 50, C = 100, D=500, M = 1000;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'M') {
            if(checker == 5) sum += M-2*C;
            else sum += M;
            checker = 7;
        }
        else if(s[i] == 'D') {
            if(checker == 5) sum += D-2*C;
            else sum += D;
            checker = 6;
        }
        else if(s[i] == 'C') {
            if(checker == 3) sum += C - 2*X;
            else sum += C;
            checker = 5;
        }
        else if(s[i] == 'L') {
            if(checker == 3) sum += L - 2*X;
            else sum += L;
            checker = 4;
        }
        else if(s[i] == 'X'){
            if(checker == 1) sum += X - 2*I;
            else sum += X;
            checker = 3;
        }
        else if(s[i] == 'V'){
            if(checker == 1) sum += V - 2*I;
            else sum += V;
            checker = 2;
        }
        else if(s[i] == 'I'){
            sum += I;
            checker = 1;
        }
    }
    return sum;
}
int main() {
    string s = "MCMXLVIII";
    cout << roman(s);
    return 0;
}