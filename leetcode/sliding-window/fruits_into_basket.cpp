// https://leetcode.com/problems/fruit-into-baskets/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int> &fruits) {
      map<int, int> cArr;
      int maxCount = 0, l = 0, r = 0;

      while (l <= r && r < fruits.size()) {
        cArr[fruits[r]]++;

        if (cArr.size() > 2) {
          if(--cArr[fruits[l]] == 0){
            cArr.erase(fruits[l]);
          }
          l++;
        }

        maxCount = max(maxCount, r - l + 1);
        r++;
      }

      return maxCount;
    }
};

int main() {
  Solution sol;
  vector<int> arr1 = {1, 2, 1};
  vector<int> arr2 = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
  vector<int> arr3 = {1, 2, 3, 2, 2, 2, 5};

  int count = sol.totalFruit(arr3);
  cout << "Count " << count << endl;
}