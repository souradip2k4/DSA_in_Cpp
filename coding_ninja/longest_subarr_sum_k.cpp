// https://www.naukri.com/code360/problems/longest-subarray-with-sum-k_6682399
#include <iostream>
#include <vector>

using namespace std;

int longestSubarrayWithSumK(vector<int> &arr, long long k) {
  int size = arr.size();
  int left = 0, right = 0;
  long long sum = 0;
  int maxLength = 0;

  while (right < size) {
    sum += arr[right];
    while (left <= right && sum > k) {
      sum -= arr[left];
      left++;
    }

    if (sum == k) {
      maxLength = max(maxLength, right - left + 1);
    }
    right++;
  }

  return maxLength;
}

int main() {

  vector<int> arr = {1, 2, 3, 1, 1, 1, 1};
  vector<int> arr2 = {2, 2, 4, 1, 2};
  vector<int> arr3 = {2, 3, 1, 1};
  vector<int> arr4 = {0, 2, 5, 3, 3, 4, 4, 3, 0, 5, 5, 4, 4, 4, 3, 2, 0, 2, 3, 1, 3, 0, 4, 3, 1, 4, 5, 2, 4, 3, 1, 4, 5,
                      0, 3, 4, 0};


  int length = longestSubarrayWithSumK(arr4, 52);

  cout << "Longest subarray length: " << length << endl;
  return 0;
}