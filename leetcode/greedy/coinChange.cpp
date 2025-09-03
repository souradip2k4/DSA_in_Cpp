// https://leetcode.com/problems/coin-change/description/
// 322. Coin Change

#include<bits/stdc++.h>
using namespace std;

// Using greedy algorithm
int coinChange(vector<int>& coins, int amount) {
  if (amount == 0) {
    return 0;
  }

  sort(coins.begin(), coins.end());
  int r = coins.size() - 1;
  while (r >= 0 && coins[r] > amount) {
    r--;
  }

  int sum = 0, cnt = 0;
  while (r >= 0) {
    int checkValSum = sum + coins[r];

    if (checkValSum <= amount) {
      cnt++;
      sum = checkValSum;
    }
    else {
      checkValSum -= coins[r];
      r--;
    }
  }


  return (cnt == 0 || amount - sum > 0) ? -1 : cnt;

}

int main() {

  int n, amt;
  cin >> n;
  cin >> amt;

  vector<int> coins(n);
  for (int& num : coins) {
    cin >> num;
  }

  cout << coinChange(coins, amt) << endl;
}

