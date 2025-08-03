// https://leetcode.com/problems/longest-consecutive-sequence/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    vector<int> consArr;
    int longest = INT_MIN, count = 0, n = nums.size();
    unordered_set<int> s1;

    for (int i = 0; i < n; i++) {
      s1.insert(nums[i]);
    }

    /*for (auto it = s1.begin(); it != s1.end(); it++) {
      if (s1.find(*it - 1) == s1.end()) {
        count = 1;
        int x = *it;
        while (s1.find(x + 1) != s1.end()) {
          x += 1;
          count++;
        }
      }

      longest = max(count, longest);
    }*/

    for (int num: s1) {
      if (s1.find(num + 1) != s1.end()) {
        count = 1;
        int temp = num + 1;
        while (s1.find(temp) != s1.end()) {
          temp++;
          count++;
        }
      }

      longest = max(longest, count);
    }
    return longest;
  }
};

int main() {
  vector<int> arr1 = {100, 4, 200, 1, 3, 2};
  vector<int> arr2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};

  Solution sol;
  //  cout << *(arr.end()- 1)  << endl;
  int count = sol.longestConsecutive(arr2);

  cout << "Tot size of consecutive array: " << count << endl;
}
