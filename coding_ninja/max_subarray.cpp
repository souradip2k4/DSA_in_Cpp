// https://www.naukri.com/code360/problems/maximum-subarray-sum_630526
#include<iostream>
#include<vector>
#include <climits>

using namespace std;

long long maxSubarraySum(vector<int> arr, int n) {
  long long int sum = 0, maximumSum = 0;
  int start = 0, end = 0, count = 0;

  for (int i = 0; i < n; i++) {
    sum = sum + arr[i];

    if (sum > maximumSum) {
      maximumSum = sum;
    }
    count++;
    if (sum < 0) {
      sum = 0;
      count = 0;
    }
  }

  cout << "Max length of subarray: " << count << endl;
  return maximumSum;
}

int main() {
  vector<int> arr1 = {1, 2, 7, -4, 3, 2};
  vector<int> arr2 = {-3, -5, -6};

  long long int maxSum = maxSubarraySum(arr2, arr2.size());
  cout << "Sum of max subarray elements: " << maxSum << endl;
}