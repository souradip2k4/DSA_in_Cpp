// 1781. Sum of Beauty of All Substrings
// https://leetcode.com/problems/sum-of-beauty-of-all-substrings/description/

#include <bits/stdc++.h>
using namespace std;

int beautySum(string s) {
  int sum = 0;

  for (int i = 0; i < s.size(); i++) {
    // Creating a new hash array everytime before entering inner loop
    int hash[26] = {0};
    for (int j = i; j < s.size(); j++) {
      hash[s[j] - 'a']++;

      int maxFreq = INT_MIN, minFreq = INT_MAX;
      for (int &item: hash) {
        if (item > 0) {
          // If item count is 0 that means that character doesn't exist and will result in minFreq to be always 0
          maxFreq = max(maxFreq, item);
          minFreq = min(minFreq, item);
        }
      }

      sum += maxFreq - minFreq;
    }
  }

  return sum;
}

int main() {
  int r1 = beautySum("aabcb");
  int r2 = beautySum("aabcbaa");

  cout << r1 << endl;
}
