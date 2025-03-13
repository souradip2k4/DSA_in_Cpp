// https://leetcode.com/problems/longest-substring-without-repeating-characters/
// 3. Longest Substring Without Repeating Characters

#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
  if (s == "") {
    return 0;
  }

  int l = 0, r = 0, maxL = 0;
  unordered_map<int, int> uMap;

  while (r < s.size()) {
    uMap[s[r]]++;

    while(uMap[s[r]] > 1) {
      uMap[s[l]]--;
      l++;
    }
    maxL = max(maxL, r - l + 1);
    r++;
  }

  return maxL;
}

int main() {
  int res1 = lengthOfLongestSubstring("abcabcbb");
  int res2 = lengthOfLongestSubstring("bbbbb");
  int res3 = lengthOfLongestSubstring("pwwkew");

  cout << res3 << endl;
}
