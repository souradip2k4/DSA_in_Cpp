// 1358
// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

#include <bits/stdc++.h>
using namespace std;

// O(n^2)
/*int numberOfSubstrings(string s) {
  int count = 0;
  for (int i = 0; i < s.size(); i++) {
    int hash[3] = {0};

    for (int j = i; j < s.size(); j++) {
      hash[s[j] - 'a']++;
      if (hash[0] > 0 && hash[1] > 0 && hash[2] > 0) {
        count += s.size() - j; // We don't need to iterate further. In "abcabc" after j reaches 3rd pos then all the rest characters after abc will also be substrings. Including abc we get 3 more substrings
        break;
      }
    }
  }

  return count;
} */

// O(n)
int numberOfSubstrings(string s) {
  int hash[3] = {0};
  int l = 0, r = 0;
  int count = 0;

  while (l <= r && r < s.size()) {
    hash[s[r] - 'a']++;
    while (hash[0] > 0 && hash[1] > 0 && hash[2] > 0) {
      count += s.size() - r;
      hash[s[l] - 'a']--;
      l++;
    }

    r++;
  }

  return count;
}

int main() {
  int n = numberOfSubstrings("abcabc");

  cout << n << endl;
}
