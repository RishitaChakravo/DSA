#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<unordered_set>

using namespace std;

int aggressive_cows_brute(vector<int> stalls, int k, int n) {
    sort(stalls.begin(), stalls.end());
    
    int minstall = stalls[0];
    int maxstall = stalls[n-1];
    int ans = 0;

    for(int dist = 1; dist <= maxstall - minstall; dist++){
        int last = stalls[0];
        int cows = 1;

        for(int i = 0; i < n; i++) {
            if(stalls[i] - last >= dist){
                cows++;
                last = stalls[i];
            }
        }

        if(cows >= k) ans = dist;
    }
    return ans;
}

int aggressive_cows_binary(vector<int> stalls, int k, int n) {
    sort(stalls.begin(), stalls.end());
    
    int minstall = stalls[0];
    int maxstall = stalls[n-1];
    int low = minstall;
    int high = maxstall - minstall;


    while(low <= high){
        int dist = (low + high) / 2;
        int last = stalls[0];
        int cows = 1;

        for(int i = 0; i < n; i++) {
            if(stalls[i] - last >= dist){
                cows++;
                last = stalls[i];
            }
        }

        if(cows >= k) 
            low = dist + 1;
        else 
            high = dist - 1;
    }
    return high;
}

int main() {
    vector<int> vec = {0,3,4,7,10,9};
    int n = 6, k = 4;
    cout << aggressive_cows_binary(vec, k, n);
    return 0;
}