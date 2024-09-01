#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
      unordered_map<int, int> uMap;
      int n = nums.size();

      for (int i = 0; i < n; i++) {
        uMap[nums[i]]++;
      }

      for (auto elem: uMap) {
        if (elem.second == 1) {
          return elem.first;
        }
      }

      return -1;
    }
};

int main() {
  Solution soln;
  vector<int> arr = {4, 1, 2, 1, 2};

  int elem = soln.singleNumber(arr);

  cout << "Element with single occurrence: " << elem << endl;
  return 0;
}