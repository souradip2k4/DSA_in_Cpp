// https://leetcode.com/problems/majority-element-ii/
#include<bits/stdc++.h>

using namespace std;

vector<int> majorityElement(vector<int> &nums) {

  int n = nums.size();
  unordered_map<int, int> uMap;
  vector<int> result;

  for (const int &elem: nums) {
    uMap[elem]++;
  }


  for (auto start = uMap.begin(); start != uMap.end(); start++) {
    if (start->second > n / 3) {
      result.push_back(start->first);
    }
  }

  return result;
}

int main() {

  vector<int> arr1 = {3, 2, 3};
  vector<int> arr2 = {1, 2};

  vector<int> result = majorityElement(arr2);

  for(int elem: result){
    cout << elem << " ";
  }
}