// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/
#include<bits/stdc++.h>
#include <values.h>

using namespace std;

bool possible(vector<int> &arr, int mid, int k, int m) {
  int count = 0, noOfBouquets = 0;

  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] <= mid) {
      count++;
    } else {
      noOfBouquets += count / k;
      count = 0;
    }
  }

  noOfBouquets += count / k;

  return noOfBouquets >= m;
}


int minDays(vector<int> &bloomDay, int m, int k) {

  long long limit =((long long)m) * ((long long)k);
  if (bloomDay.size() < limit) {
    return -1;
  }

  int minElem = MAXINT, maxElem = MININT;
  for (auto elem: bloomDay) {
    minElem = min(minElem, elem);
    maxElem = max(maxElem, elem);
  }

  int l = minElem, h = maxElem;
  int result = h;
  int mid = l + (h - l) / 2;

  while (l < h) {
    if (possible(bloomDay, mid, k, m)) {
      result = mid;
      h = mid - 1;
    } else {
      l = mid + 1;
    }

    mid = l + (h - l) / 2;
  }

  return result;
}

int main() {
  vector<int> arr1 = {7, 7, 7, 7, 12, 7, 7}; // m = 2  k = 3
  vector<int> arr2 = {1, 10, 3, 10, 2}; // m = 3  k = 2

  int min = minDays(arr1, 2, 3);

  cout << min << endl;
}