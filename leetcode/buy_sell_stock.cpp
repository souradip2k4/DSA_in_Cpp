// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
      int maxP = 0, min = prices[0];

      for (int i = 1; i < prices.size(); i++) {
        if (prices[i] - min < 0) {
          min = prices[i];

        if (prices[i] - min > maxP) {
          maxP = prices[i] - min;
        }
      }

      return maxP;
    }
};

int main() {
  Solution soln;
  vector<int> prices = {7, 6, 5, 4, 3, 2, 1};
  int maxProfit = soln.maxProfit(prices);

  cout << "Max profit: " << maxProfit << endl;
}