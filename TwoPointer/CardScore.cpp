#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int maxScore(vector<int> cardPoints, int k)
{
    int n = cardPoints.size();

    if (k == n)
    {
        return accumulate(cardPoints.begin(), cardPoints.end(), 0);
    }

    int lsum = 0, rsum = 0, maxsum = 0;

    for (int i = 0; i < k; i++)
    {
        lsum += cardPoints[i];
    }

    maxsum = lsum;
    int last = n - 1;

    for (int i = k - 1; i >= 0; i--)
    {
        lsum -= cardPoints[i];
        rsum += cardPoints[last];
        last--;
        maxsum = max(maxsum, lsum + rsum);
    }

    return maxsum;
}

int main()
{
    vector<int> nums = {6, 2, 1, 8, 1, 2, 1, 7, 1};
    int k = 4;
    cout << maxScore(nums, k);
    return 0;
}