//
#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;

vector<vector<int>> pairSum(vector<int> &arr, int s) {
  int size = arr.size();
  vector<vector<int>> arrP;

  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      if (arr[i] + arr[j] == s) {
        if (arr[i] <= arr[j]) {
          arrP.push_back({arr[i], arr[j]});
        } else {
          arrP.push_back({arr[j], arr[i]});
        }
      }
    }
  }

  sort(arrP.begin(), arrP.end());
  return arrP;
}

int main() {
  vector<int> arr = {1, 2, 3, 4, 5};
  vector<int> arr2 = {2, -3, 3, 3, -2};

  vector<vector<int>> result = pairSum(arr2, 0);

  for (int i = 0; i < result.size(); i++) {
    cout << result[i][0] << ", " << result[i][1] << endl;
  }
}

