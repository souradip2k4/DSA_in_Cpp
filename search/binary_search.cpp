#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> &arr, int key) {
  int start = 0;
  int end = arr.size() - 1;
  int mid = start + (end - start) / 2;

  while (end >= start) {
    if (key == arr[mid]) {
      return mid;
    }

    if (key > arr[mid]) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }

    mid = start + (end - start) / 2;
  }

  return -1;
}

int main() {

  vector<int> arrEven = {10, 12, 20, 16, 45, 70};
  vector<int> arrOdd = {10, 20, 30, 35, 60, 75, 85};
  int key = 100;
  int index = binarySearch(arrOdd, key);

  cout << "Index of " << key << " is: " << index;

}