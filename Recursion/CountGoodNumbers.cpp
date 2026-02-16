#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long countGoodNumbers_brute(int n) {
    long long ways = 1; 
    while(n > 0) {
        if(n % 2 != 0) ways = ways * 5;
        else ways = ways * 4;
        n--;
    }
    return ways;
}
int main() {
    int n = 50;
    cout << countGoodNumbers_brute(n);
    return 0;
}