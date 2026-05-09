#include<iostream>
#include<bits/stdc++.h>

using namespace std;
// cnt number of primes in lesser time by reducing the prime check from sqrt(n) time to constant time
// using precomputation known as sieve of eratosthenes

vector<int> primeArr(int n) {
    vector<int> prime(n + 1, 1);
    prime[0] = 0;
    prime[1] = 0;
    for(int i = 2 ; i <= sqrt(n); i++) {
        if(prime[i] == 1) {
            for(int j = i * i; j <= n; j += i) {
                prime[j] = 0;
            }
        }
    }
    return prime;
}

int cntPrime(int N) {
    vector<int> prime = primeArr(N);
    int cnt = 0;
    for(int i = 2; i <= N; i++){
        if(prime[i] == 1) cnt++;
    }
    return cnt;
}
int main() {
    cout << cntPrime(10);
    return 0;
}