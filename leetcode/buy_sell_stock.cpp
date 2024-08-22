#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
      int maxP = 0;
      int minPrice = prices[0];

      for (int i = 1; i < prices.size(); i++) {
        // Update the minimum price encountered so far
        if (prices[i] < minPrice) {
          minPrice = prices[i];
        }
        // Calculate the potential profit and update maxP if it's the highest seen so far
        int profit = prices[i] - minPrice;
        if (profit > maxP) {
          maxP = profit;
        }
      }
      return maxP;
    }
};

int main() {
  Solution soln;
  vector<int> prices = {7, 1, 5, 3, 6, 4};
  long maxProfit = soln.maxProfit(prices);

  cout << "Max profit: " << maxProfit << endl;
  return 0;
}