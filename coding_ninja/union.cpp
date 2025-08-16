// https://www.naukri.com/code360/problems/sorted-array_6613259
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> sortedArray(vector<int> a, vector<int> b)
{
  unordered_map<int, int> uMap;

  for (auto el : a)
  {
    if (uMap.find(el) == uMap.end())
    {
      uMap[el]++;
    }
  }

  for (auto el : b)
  {
    if (uMap.find(el) == uMap.end())
    {
      uMap[el]++;
    }
  }

  vector<int> keys;
  keys.reserve(uMap.size()); // Reserve space for efficiency

  for (const auto entry : uMap)
  {
    keys.push_back(entry.first);
  }

  sort(keys.begin(), keys.end());
  return keys;
}

int main()
{
  vector<int> arr1, arr2, resArr;
  arr1 = {1, 2, 3, 4, 5};
  arr2 = {2, 3, 5};

  resArr = sortedArray(arr1, arr2);

  for (auto elem : resArr)
  {
    cout << elem << ", ";
  }
}