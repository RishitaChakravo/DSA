#include <bits/stdc++.h>
using namespace std;

int main(){
    //sort array with 0, 1, 2
    //also called Dutch National Flag Algo
    int a[13] = {0,1,2,1,0,2,1,1,2,0,0,1,2};
    int low = 0;
    int mid = 0;
    int high = 12;

    while(mid <= high){
        if(a[mid] == 0){
            swap(a[mid], a[low]);
            low = low + 1;
            mid = mid + 1; 
        }
        else if(a[mid] == 1){
            mid = mid + 1;
        } 
        else if(a[mid] == 2){
            swap(a[mid], a[high]);
            high = high - 1;
        }
    }

    for(int i = 0; i< 13; i++){
        cout<<a[i]<< " ";
    }

    return 0;
}