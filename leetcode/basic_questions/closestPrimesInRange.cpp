// 2523. Closest Prime Numbers in Range
// https://leetcode.com/problems/closest-prime-numbers-in-range/description/

#include<bits/stdc++.h>
using namespace std;

// Method 1
/*
vector<int> closestPrimes(int left, int right) {
  vector<int> isPrime(right + 1, 1);
  isPrime[0] = isPrime[1] = 0;
  for (int i = 2; i * i <= right; i++) {
    if (isPrime[i]) {
      for (int j = i * i; j <= right; j += i) {
        isPrime[j] = 0;
      }
    }
  }

  vector<int> pair(2, -1), check;
  int minDiff = INT_MAX;


  for (int i = left; i <= right; i++) {
    if (isPrime[i]) {

      check.push_back(i);
      if (check.size() == 2) {
        if (check[1] - check[0] < minDiff) {
          pair[0] = check[0];
          pair[1] = check[1];

          minDiff = check[1] - check[0];
        }
        check[0] = check[1];
        check.pop_back();
      }

    }
  }

  return pair;

}
*/

// Method 2
vector<int> closestPrimes(int left, int right) {
  vector<int> isPrime(right + 1, 1);
  isPrime[0] = isPrime[1] = 0;
  for (int i = 2; i * i <= right; i++) {
    if (isPrime[i]) {
      for (int j = i * i; j <= right; j += i) {
        isPrime[j] = 0;
      }
    }
  }

  vector<int> pair(2, -1);
  int prev = -1, minDiff = INT_MAX;

  for (int i = left; i <= right; i++) {

    if (isPrime[i]) {
      if (prev != -1 && i - prev < minDiff) {
        minDiff = i - prev;
        pair = { prev, i };
      }

      prev = i;
    }
  }

  return pair;
}