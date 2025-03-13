// https://leetcode.com/problems/merge-intervals/description/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
      const int size = intervals.size();
      if (size == 0) {
        return {};
      }

      sort(intervals.begin(), intervals.end());

      vector<vector<int>> merged(0);
      merged.push_back(intervals[0]);

      for (int i = 1; i < size; i++) {
        if (merged.back()[1] >= intervals[i][0]) {
          merged.back()[1] = max(merged.back()[1], intervals[i][1]);

        } else {
          merged.push_back(intervals[i]);
        }
      }

      return merged;
    }
};

int main() {
  Solution sol;
  vector<vector<int>> intervals = {
          {1, 4},
          {2, 3}
  };

  vector<vector<int>> result = sol.merge(intervals);

  cout << "Size of result array: " << result.size() << endl;
  for (int i = 0; i < result.size(); i++) {
    cout << " [" << result[i][0] << ", " << result[i][1] << "], ";
  }
}