#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int n = 10;
    int arr[] = {3,5,7,1,9,8,4,6,2,0};

    for(int i=0; i<n; i++){
        int j = i;
        while(j>0 && arr[j-1] > arr[j]){
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }

    for (int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}

//SELECTION SORT
// int n = 10;
//     int arr[] = {3,2,6,7,8,1,4,5,9,0};
//     for(int i=0; i<n-2; i++){
//         int min = i;
//         for(int j=i; j<=n-1; j++){
//             if(arr[j]<arr[min]){
//                 min = j;
//             }
//         }
//         int temp = arr[min];
//         arr[min] = arr[i];
//         arr[i] = temp;
//     }

//     for (int i=0; i<n; i++)
//     {
//         cout<<arr[i]<<" ";
//     }


//BUBBLE SORT
// for(int i=n-1; i>=0; i--){
//     int didSwap =0;
//     for(int j=0; j<=i; j++){
//         if(arr[j]>arr[j+1]){
//             int temp = arr[j];
//             arr[j] = arr[j+1];
//             arr[j+1] = temp;
//             didSwap = 1;
//         }
//     }

//INSERTION SORT
// for(int i=0; i<n; i++){
//     int j = i;
//     while(j>0 && arr[j-1] > arr[j]){
//         int temp = arr[j-1];
//         arr[j-1] = arr[j];
//         arr[j] = temp;
//         j--;
//     }
// }