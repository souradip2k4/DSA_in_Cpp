// https://www.naukri.com/code360/problems/longest-subarray-with-sum-k_5713505
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int getLongestSubarray(vector<int>& arr, long long k) {
  unordered_map<long long, int> mpp;
  int n = arr.size();
  long long prefixSum = 0, rem = 0;
  int maxL = 0;

  mpp[0] = -1;
  for (int i = 0; i < n; i++) {
    prefixSum += arr[i];
    rem = prefixSum - k;

    if (mpp.find(rem) != mpp.end()) {
      int ind = mpp[rem];
      maxL = max(maxL, i - ind);
    }

    if (mpp.find(prefixSum) == mpp.end()) { // For [2, 0, 0, 3]
      mpp[prefixSum] = i;
    }
  }

  return maxL;
}

int main() {

  vector<int> arr = { 1, 2, 3, 1, 1, 1, 1, 4, 2, 3 }; // 3
  vector<int> arr2 = { 2, 0, 0, 3 }; // 3 (This algo works for both signed and unsigned int)
  vector<int> arr3 = { -1, 0, 1, 1, -1, -1, 0 }; // 0

  int length = getLongestSubarray(arr, 3);

  cout << "Longest subarray length: " << length << endl;
  return 0;
}