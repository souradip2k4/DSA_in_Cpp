// https://leetcode.com/problems/longest-consecutive-sequence/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
      vector<int> consArr;
      int longest = 0, count = 0, n = nums.size();
      unordered_set<int> s1;

      for (int i = 0; i < n; i++) {
        s1.insert(nums[i]);
      }

      for (auto it = s1.begin(); it != s1.end(); it++) {
        if (s1.find(*it - 1) == s1.end()) {
          count = 1;
          int x = *it;
          while (s1.find(x + 1) != s1.end()) {
            x += 1;
            count++;
          }
        }

        longest = max(count, longest);
      }
      return longest;
    }
};

int main() {
  vector<int> arr = {100, 4, 200, 1, 3, 2};

  Solution sol;
//  cout << *(arr.end()- 1)  << endl;
  int count = sol.longestConsecutive(arr);

  cout << "Tot size of consecutive array: " << count << endl;
}