// https://www.naukri.com/code360/problems/maximum-subarray-sum_630526
#include<iostream>
#include<vector>
#include <climits>
using namespace std;

long long maxSubarraySum(vector<int> arr, int n) {
  long long int sum = 0, maximum = -1;

  for (int i = 0; i < n; i++) {
    sum = sum + arr[i];

    if(sum > maximum){
      maximum = sum;
    }

    if(sum < 0){
      sum = 0;
    }
  }

  if(maximum < 0){
    return 0;
  } else {
    return maximum;
  }
}
int main() {
  vector<int> arr1 = {1, 2, 7, -4, 3, 2};
  vector<int> arr2 = {-3, -5, -6};

  long long int maxSum = maxSubarraySum(arr1, arr1.size());
  cout << "Sum of max subarray elements: " << maxSum << endl;
}