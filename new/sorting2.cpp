
#include <bits/stdc++.h>
#include <iostream>

using namespace std;



int main(){
    int arr[6]; 
    
    for(int i = 0; i<6; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

// void merge(int arr[], int low, int mid, int high){
//     int left = low;
//     int right = mid + 1;
//     vector<int> temp;

//     while(left <= mid && right <= high){
//         if(arr[left] <= arr[right]){
//             temp.push_back(arr[left]);
//             left++;
//         } else {
//             temp.push_back(arr[right]);
//             right++;
//         }
//     }

//     while(left <= mid){
//         temp.push_back(arr[left]);
//         left++;
//     }

//     while(right<=high){
//         temp.push_back(arr[right]);
//         right++;
//     }

//     for(int i = low; i<=high; i++){
//         arr[i] = temp[i - low];
//     }
// }

// void mS(int arr[], int low, int high){
//     if(low >= high) return;

//     int mid = (low + high) / 2;

//     mS(arr, low, mid);
//     mS(arr, mid + 1, high);
//     merge(arr, low, mid, high);
// }

// int main(){
//     int arr[] = {0,9,1,6,5,2,4,8,3,7};

//     mS(arr, 0, 10);

//     for(int i =0; i<10; i++){
//         cout<<arr[i]<<" ";
//     }
//     return 0;
// }

// void insert_sort(int arr[], int n, int i){
//     if(i == 1) return;
    
//     int j = n - i + 1;
//     while( j > 0 && arr[j - 1] >= arr[j]){
//         int temp = arr[j-1];
//         arr[j-1] = arr[j];
//         arr[j] = temp;
//         j--;
//     }

//     insert_sort(arr, n, i - 1);
// }

//
// void bubble_sort(int arr[], int n){
//     if(n == 1) return;
//     for(int i = 0; i <= n -2 ; i++){
//         if(arr[i] > arr[i + 1]){
//             int temp = arr[i];
//             arr[i] = arr[i+1];
//             arr[i+1] = temp;
//         }
//     }

//     bubble_sort(arr, n - 1);
// }

//QUICK SORT
// int work(int arr[], int low, int high){
//     int i = low;
//     int j = high;

//     int pivot = arr[low];
    
//     while( j > i){
    
//         while(arr[i] <= pivot && i <=high - 1){
//             i++;
//         }

//         while(arr[j] > pivot && j >= low + 1){
//             j--;
//         }

//         if(i < j){
//             swap(arr[i], arr[j]);
//         }
//     }
    
//     swap(arr[low], arr[j]);
//     return j;
// }

// void qs(int arr[], int low, int high){
//     if(low < high){
//         int p = work(arr, low, high);
//         qs(arr, low, p - 1);
//         qs( arr, p + 1, high);
//     }
// }
// int arr[] = {0,3,2,1,6,5,8,7};

//     qs(arr, 0, 7);

//     for(int i =0; i<8; i++){
//         cout<<arr[i]<<" ";
//     }
