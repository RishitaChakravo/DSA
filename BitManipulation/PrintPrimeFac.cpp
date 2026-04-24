#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool checkIfPrime(int n) {
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) return false;
    }
    return true;
}

vector<int> primefac(int N) {
    vector<int> ans;
    for(int i = 2; i <= N; i++) {
        if(N % i == 0) {
            if(checkIfPrime(i)) ans.push_back(i);
        }
    }
    return ans;
}

vector<int> primefac2(int N) {
    vector<int> ans;
    for(int i = 2; i <= sqrt(N); i++) {
        if(N%i == 0) {
            if(checkIfPrime(i)) ans.push_back(i);
            if(N/i != i && checkIfPrime(N/i)) ans.push_back(N/i);
        }
    }
    return ans;
}

vector<int> primefac3(int n) {
    vector<int> ans;
    for(int i = 2; i <= sqrt(n); i++) {
        if(n%i == 0) {
            ans.push_back(i);
            while(n%i == 0) {
                n /= i;
            }
        }
    }
    if(n != 1) ans.push_back(n);
    return ans;
}
int main(){
    vector<int> ans = primefac(4999);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}