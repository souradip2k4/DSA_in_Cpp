// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/
// 1423. Maximum Points You Can Obtain from Cards

#include<bits/stdc++.h>
using namespace std;

int maxScore(vector<int>& cardPoints, int k) {
  int lSum = 0, rSum = 0;

  for(int i = 0; i < k; i++){
    lSum += cardPoints[i];
  }

  int maxSum = lSum;

  int n = cardPoints.size();
  for(int i = 0; i < k ; i++){
    lSum -= cardPoints[k - 1 - i];
    rSum += cardPoints[n - 1 - i];

    maxSum = max(maxSum, lSum + rSum);
  }

  return maxSum;
}

int main() {
  vector<int> arr1 = {1, 2, 3, 4, 5, 6, 1};
  vector<int> arr2 = {2, 2, 2};
  vector<int> arr3 = {9, 7, 7, 9, 7, 7, 9};

  int res1 = maxScore(arr1, 3);
  int res2 = maxScore(arr1, 2);
  int res3 = maxScore(arr1, 7);

  cout << res1 << endl;
}
