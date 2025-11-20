#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> pascal_triangle(int numRows) {
    vector<vector<int>> result;
    for(int i = 0; i < numRows; i++) {
        vector<int> tempvec(i+1);
        for(int j = 0; j <= i; j++) {
            if(j==0 || j==i) 
                tempvec[j] = 1;
            else tempvec[j] = result[i-1][j-1] + result[i-1][j];
        }
        result.push_back(tempvec);
    }
    return result;
}

void print_pascal_triangle(vector<vector<int>> vec) {
    for(int i = 0; i < vec.size(); i++) {
        for(int j = 0; j < vec[i].size(); j++) {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    vector<vector<int>> result = pascal_triangle(10);
    print_pascal_triangle(result);
    return 0;
}