// https://leetcode.com/problems/jump-game/
// Jump game

#include<bits/stdc++.h>
using namespace std;

bool canJump(vector<int>& nums) {

  if (nums.size() == 1) {
    return true;
  }
  int maxJump = 0;

  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] == 0 && maxJump <= i && i != nums.size() - 1) {
      return false;
    }

    maxJump = max(maxJump, i + nums[i]);
  }

  return maxJump >= nums.size() - 1;
}
