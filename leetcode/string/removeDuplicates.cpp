#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  int removeDuplicates(vector<int>& nums) {
    int cnt = 1;
    int prev = nums[0];
    int k = 1;

    int i = 1;
    for (int i = 1; i < nums.size(); i++) {
      // Skip duplicates
      if (nums[i] != prev) {
        nums[k] = nums[i];
        cnt++;
        k++;
      }

      prev = nums[i];

    }

    return cnt;
  }
};

int main() {
  vector<int> arr = { -2, 2, 4, 4, 4, 4, 5, 5 };

  Solution sol;
  int k = sol.removeDuplicates(arr);
  cout << k << endl;
  // Print rearranged array
  for (int x : arr) cout << x << " ";
}