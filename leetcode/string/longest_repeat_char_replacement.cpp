// https://leetcode.com/problems/longest-repeating-character-replacement/description/
#include <bits/stdc++.h>
using namespace std;

// Using custom hashmap array
/*int characterReplacement(string s, int k) {
  int hash[26] = {0};
  int l = 0, r = 0, maxLen = 0, maxF = 0;

  while (l <= r && r < s.size()) {
    hash[s[r] - 'A']++;
    maxF = max(maxF, hash[s[r] - 'A']);

    if ((r - l + 1) - maxF <= k) {
      maxLen = max(maxLen, r - l + 1);
    } else {
      hash[s[l] - 'A']--;
      maxF = 0;
      l++;
    }
    r++;
  }

  return maxLen;
}*/


// Using unordered map
int characterReplacement(string s, int k) {
  unordered_map<char, int> uMap;
  int l = 0, r = 0, maxLen = 0, maxF = 0;

  while (l <= r && r < s.size()) {
    uMap[s[r]]++;

    maxF = max(maxF, uMap[s[r]]);

    if ((r - l + 1) - maxF <= k) {
      maxLen = max(maxLen, r - l + 1);
    } else {
      uMap[s[l]]--;
      l++;
      maxF = 0;
    }

    r++;
  }

  return maxLen;
}

int main() {
  int maxLength = characterReplacement("AABABBA", 1);

  cout << "Longest substring with same character after replacementL " << maxLength << endl;
}
