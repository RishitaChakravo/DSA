#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    map<int, int> mpp;

    int arr[10] = {1,2,3,4,1,1,2,3,11,1};

    for(int i=0; i<10; i++){
        mpp[arr[i]]++;
    }
    cout<< mpp[1];

    return 0;
}

//NUMBER HASHING
// int arr[11] = {1,1,1,2,2,3,4,5,8,8,1000};

//     int h[10000] = {0};
//     for(auto i : arr){
//         h[i]++;
//     }

//     cout<< h[1] << endl;

//My logic for CHARACTER HASHING
// int alpha[10] = {' ','a', 'b', 'c', 'd', 'e', 'f', 'A', 'B', 'C'};

//     string s = "abcdeaab   cdemnh";

//     int h[12] = {0};

//     for (size_t i = 0; i < s.length(); i++) {
//         for(int j=0; j<10; j++){
//             if(s[i] == alpha[j]){
//                 h[j]++;
//             }
//         }
//     }

//     cout << h[0];
//     cout<< h[1];

//SAME USING ASCII VALUE
// string s = "abcdefaabbccddeeffgg";

//     int h[256] = {0};

//     for(size_t i = 0; i<s.length(); i++){
//         h[s[i]]++;
//     }

//     cout << h[102];

//NOW THE BEST WAY is using "MAP"