#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> mergeintervals(vector<vector<int>> intervals) {
    vector<vector<int>> result;
    sort(intervals.begin(), intervals.end());
    for(int i = 0; i < intervals.size(); i++) {
        if(result.empty() || result.back()[1] < intervals[i][0]){
            result.push_back(intervals[i]);
        } else {
            result.back()[1] = max(result.back()[1], intervals[i][1]);
        }
    }
    return result;
}

void print(vector<vector<int>> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> temp = {{1, 3}, {2, 6}, {9,11}, {8,9}, {2,4}, {15,18}, {16, 17}};
    vector<vector<int>> result = mergeintervals(temp);
    print(result);
}