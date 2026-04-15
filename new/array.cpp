#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int linearSearch(vector<int> arr, int f){
    int i =0;
    
    while(i < arr.size()){
        if(arr[i] == f){
            return i + 1;
        }
        i++;
    }
    return -1;
}

int main(){
    int arr[] = {1,6,5,8,11};
    int target = 14;
    
    return 0;
}
//Better : HashMap
// int flag = 0;
    // map<int,int> mpp;
    // for(int i = 0; i< 5; i++){
    //     int a = arr[i];
    //     int more = target - a;
    //     if(mpp.find(more) != mpp.end()){
    //         flag = 1;
    //     } else {
    //         mpp[a] = i;
    //     }
    // }

    //Brute
    // int target = 14;
    // int flag = 0;
    // for(int i = 0; i<5; i++){
    //     for(int j = i; j < 5; j++){
    //         if(arr[i] + arr[j] == target){
    //             flag = 1;
    //             cout<<"["<<i<<", "<<j<<"]";
    //             break;
    //         }
    //     }
    // }

    // if(flag == 0) cout<<false;
    // else cout<< true;

//REMOVE DUPLICATE
//brute force :
//int arr[] = {1,1,2,3,4,4,5,6,6};
// set<int> st;

// for(int i = 0; i<9; i++){
//     st.emplace(arr[i]);
// }

// for(auto it : st){
//     cout<< it << " ";
//     it++;
// }

//optimal solution :
//int arr[] = {1,1,2,3,4,4,5,6,6};


//rotate array by k
// int arr[] = {1,2,3,4,5,6,7};
//     int n = 7;
//     int k = 8;
//     if(k > n) {
//         k = k % n;
//     }

//     while(k>0){
//         int temp = arr[6];
//         for(int i = 5; i>=0; i--){
//             arr[i + 1] = arr[i];
//         }
//         arr[0] = temp;
//         k--;
//     }
    
//     for(int i  =0; i<n; i++){
//         cout<<arr[i] <<" ";
//     }

//Brute force
// set<int> st;
//     for(int i = 0; i < 6; i++){
//         st.emplace(arr1[i]);
//     }

//     for(int i = 0; i < 5; i++ ){
//         st.emplace(arr2[i]);
//     }
    
//     for(auto it : st){
//         cout << it << " ";
//     }

//optimal solution
// int n1 = sizeof(arr1) / sizeof(arr1[0]);
// int n2 = sizeof(arr2) / sizeof(arr2[0]);
// int i = 0;
// int j = 0;

// vector<int> unionArr;

// while( i < n1 && j < n2){
//     if(arr1[i] <= arr2[j]){
//         if(unionArr.size() || unionArr.back() != arr1[i]){
//             unionArr.push_back(arr1[i]);
//         }
//         i++;
//     } else {
//         if(unionArr.size() || unionArr.back() != arr2[j]){
//             unionArr.push_back(arr2[j]);
//         }
//         j++;
//     }
    
//     while( i < n1) {
//         if(unionArr.size() || unionArr.back() != arr1[i]){
//             unionArr.push_back(arr1[i]);
//         }
//         i++;
//     }

//     while( j < n2) {
//         if(unionArr.size() || unionArr.back() != arr2[j]){
//             unionArr.push_back(arr2[j]);
//         }
//         j++;
//     }
// }

//check remaining solutions in leetcode
// vector<int> arr = {9,6,4,2,3,5,7,0,1};

//     int n = arr.size();

//     for(int i = 0; i<n; i++){
//         int flag = 0;
//         for(int j =0; j<n; j++){
//             if(arr[j] == i){
//                 flag = 1;
//                 break;
//             }
//         }
//     }

// int arr[] = {1,1,0,1,1,1};
//     vector<int> cntOne(0);

//     int cnt = 0;
//     int max = 0;

//     for(int i = 0; i < 6; i++){
//         if(arr[i] == 1){
//             cnt++;
//         } else {
//             cntOne.push_back(cnt);
//             cnt = 0;
//         }
//     }
//     cntOne.push_back(cnt);
    
//     for(int i = 0; i < cntOne.size() ; i++ ){
//         if(cntOne[i] > max) {
//             max = cntOne[i];
//         }
//     }

//     cout << max << endl;