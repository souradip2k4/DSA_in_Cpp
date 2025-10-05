// https://leetcode.com/problems/jump-game-ii/
// 45. Jump Game II

#include<bits/stdc++.h>
using namespace std;

int jump(vector<int>& nums) {

  int cnt = 0;
  int n = nums.size();
  int i = 0;

  while (i < n - 1) {
    int nextMaxInd = min(i + nums[i], n - 1);
    int maxJump = INT_MIN;
    int bestNextInd = i + 1;

    if (nextMaxInd == n - 1) {
      cnt++;
      break;
    }

    for (int j = i + 1; j <= nextMaxInd; j++) {

      if (j + nums[j] > maxJump) {
        maxJump = j + nums[j];
        bestNextInd = j;
      }
    }

    cnt++;
    i = bestNextInd;
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
