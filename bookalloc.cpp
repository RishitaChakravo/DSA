#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<numeric>

using namespace std;

int bookalloc(vector<int> books, int m) {
    int maxpages = *max_element(books.begin(), books.end());
    int allpages = accumulate(books.begin(), books.end(), 0); 
    for(;maxpages <=allpages; maxpages++) {
        int sumpages = 0;
        int children = 1;
        for(int i = 0; i < books.size(); i++) {
            if(sumpages + books[i] > maxpages) {
                children++;
                sumpages = books[i];
            } else {
                sumpages += books[i];
            }
        }
        if(children <= m) return maxpages;
    }
    return -1;
}

int bookalloc_binary(vector<int> books, int m) {
    int low = *max_element(books.begin(), books.end());
    int high = accumulate(books.begin(), books.end(), 0); 
    int maxpages = -1;
    while(low <= high) {
        int mid = (low + high) / 2;
        int sumpages = 0;
        int children = 1;
        for(int i = 0; i < books.size(); i++) {
            if(sumpages + books[i] > mid) {
                children++;
                sumpages = books[i];
            } else {
                sumpages += books[i];
            }
        }
        if(children <= m)
            {maxpages = mid;
            high = mid- 1;}
        else
            low = mid + 1;
    }
    return maxpages;
}
int main() {
    vector<int> books = {25,46,28,49,24};
    int m = 4;
    cout << bookalloc_binary(books, m);
    return 0;
}