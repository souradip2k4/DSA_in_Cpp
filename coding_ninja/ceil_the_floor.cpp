// https://www.naukri.com/code360/problems/ceiling-in-a-sorted-array_1825401
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

pair<int, int> getFloorAndCeil(vector<int> &arr, int n, int x) {
  pair<int, int> ceilFloor = {-1, -1};

  for (int i = 0; i < n; i++) {
    if (arr[i] <= x) {
      ceilFloor.first = arr[i];
    }

    if (arr[i] >= x) {
      ceilFloor.second = arr[i];
      break;
    }
  }
  
  return ceilFloor;
}

int main() {
  vector<int> arr = {3, 4, 7, 8, 8, 10};

  pair<int, int> ceilFloor = getFloorAndCeil(arr, arr.size(), 7);

  cout << ceilFloor.first << " " << ceilFloor.second << endl;
}