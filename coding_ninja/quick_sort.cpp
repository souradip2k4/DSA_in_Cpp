#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int low, int high) {
  int i = low, j = high;
  int pivot = arr[low];  // Store the pivot value

  while (i < j) {
    while (arr[i] <= pivot && i < high) {
      i++;
    }
    while (arr[j] > pivot && j > low) {
      j--;
    }

    if (i < j) {
      swap(arr[i], arr[j]);
    }
  }

  swap(arr[low], arr[j]);

  return j;
}

vector<int> quickSort(vector<int> &arr, int low, int high) {
  if (low < high) {
    int pIndex = partition(arr, low, high);
    quickSort(arr, low, pIndex - 1);
    quickSort(arr, pIndex + 1, high);
  }

  return arr;
}

int main() {
  vector<int> arr = {4, 2, 1, 5, 3};

  vector<int> resArray = quickSort(arr, 0, arr.size() - 1);

  for (auto elem: resArray) {
    cout << elem << " ";
  }
  return 0;
}
