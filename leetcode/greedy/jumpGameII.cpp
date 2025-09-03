// https://leetcode.com/problems/jump-game-ii/
// 45. Jump Game II

#include<bits/stdc++.h>
using namespace std;

int jump(vector<int>& nums) {

  int cnt = 0;
  int n = nums.size();
  int i = 0;

  while (i < n - 1) {
    int nextInd = min(i + nums[i], n - 1);
    int maxJump = i + nums[i];
    int bestInd = i + 1;
    if (i + nums[i] >= nums.size() - 1) {
      cnt++;
      break;
    }

    for (int j = i + 1; j <= nextInd; j++) {

      if (j + nums[j] > maxJump) {
        maxJump = j + nums[j];
        bestInd = j;
      }
    }

    cnt++;
    i = bestInd;
  }

  return cnt;
}

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int& num : nums) {
    cin >> num;
  }

  cout << jump(nums) << endl;

}
