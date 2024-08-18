// https://www.naukri.com/code360/problems/first-and-last-position-of-an-element-in-sorted-array_1082549
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int firstOccurrence(int arr[], int n, int key) {

  int start = 0, end = n - 1, ans = -1;
  int mid = start + (end - start) / 2;

  while (end >= start) {
    if (arr[mid] == key) {
      ans = mid;
      end = mid - 1;
    } else if (arr[mid] < key) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }

    mid = start + (end - start) / 2;
  }

  return ans;
}


int lastOccurrence(int arr[], int n, int key) {
  int start = 0, end = n - 1, ans = -1;
  int mid = start + (end - start) / 2;

  while (end >= start) {
    if (arr[mid] == key) {
      ans = mid;
      start = mid + 1;
    } else if (arr[mid] < key) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }

    mid = start + (end - start) / 2;
  }

  return ans;
}

pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k) {
  pair<int, int> p;
  p.first = firstOccurrence(arr.data(), n, k);
  p.second = lastOccurrence(arr.data(), n, k);

  return p;
}


int main() {
  vector<int> arr = {1, 2, 2, 2, 2, 2, 2, 3, 4, 4, 4, 4};
  pair<int, int> result = firstAndLastPosition(arr, arr.size(), 4);
  cout << "First occurrence: " << result.first << endl;
  cout << "Last occurrence: " << result.second << endl;

  cout << INT_MAX << endl;
  return 0;
}
