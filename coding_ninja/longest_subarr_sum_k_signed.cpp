// https://www.naukri.com/code360/problems/longest-subarray-with-sum-k_5713505
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int getLongestSubarray(vector<int> &arr, long long k) {
  unordered_map<long long, int> prefixSum;
  int n = arr.size();
  long long sum = 0, rem = 0;
  int maxL = 0;

  for (int i = 0; i < n; i++) {
    sum += arr[i];
    if (sum == k) {
      maxL = max(maxL, i + 1);
      prefixSum[sum] = i;
    }
    rem = sum - k;

    if (prefixSum.find(rem) != prefixSum.end()) {
      int ind = prefixSum[rem];
      maxL = max(maxL, i - ind);
    }

    if (prefixSum.find(sum) == prefixSum.end()) { // For [2, 0, 0, 3]
      prefixSum[sum] = i;
    }
  }

  return maxL;
}

int main() {

  vector<int> arr = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3}; // 3
  vector<int> arr2 = {2, 0, 0, 3}; // 3 (This algo works for both signed and unsigned int)
  vector<int> arr3 = {-1, 0, 1, 1, -1, -1, 0}; // 0

  int length = getLongestSubarray(arr, 3);

  cout << "Longest subarray length: " << length << endl;
  return 0;
}