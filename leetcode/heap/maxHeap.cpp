#include<bits/stdc++.h>
using namespace std;

class maxHeap {
  public:
  vector<int> heap;

  void insert(int val) {
    heap.push_back(val);

    int i = heap.size() - 1;
    while (i > 0) {
      int parentI = (i - 1) / 2;

      if (heap[parentI] < heap[i]) {
        swap(heap[parentI], heap[i]);
        i = parentI;

      }
      else {
        return;
      }
    }
  }

  void deleteFromHeap() {
    int n = heap.size();

    if (n == 0) {
      cout << "Nothing to delete from heap" << endl;
      return;
    }

    swap(heap[0], heap[n - 1]);
    n--;
    heap.pop_back();

    int i = 0;
    while (i < n) {
      int leftI = 2 * i + 1;
      int rightI = 2 * i + 2;
      int largest = i;
      if (leftI < n && heap[largest] < heap[leftI]) {
        largest = leftI;
      }

      if (rightI < n && heap[largest] < heap[rightI]) {
        largest = rightI;
      }

      if (i == largest) {
        return;
      }

      swap(heap[largest], heap[i]);
      i = largest;

    }
  }

  int top() {
    if (heap.size() == 0) {
      cout << "Heap empty " << endl;
      return -1;
    }

    return heap[0];
  }

  void print() {
    for (int num : heap) {
      cout << num << ", ";
    }
    cout << endl;
  }
};


void maxHeapify(vector<int>& heap, int i, int n) {

  int largest = i;
  int leftI = i * 2 + 1;
  int rightI = i * 2 + 2;

  if (leftI < n && heap[largest] < heap[leftI]) {
    largest = leftI;
  }

  if (rightI < n && heap[largest] < heap[rightI]) {
    largest = rightI;
  }

  if (largest != i) {
    swap(heap[largest], heap[i]);
    maxHeapify(heap, largest, n);
  }
}

void heapSort(vector<int>& heap) {
  int i = heap.size() - 1;

  while (i > 0) {
    swap(heap[0], heap[i]);

    maxHeapify(heap, 0, i);
    i--;
  }
}


int main() {
  maxHeap m;
  m.insert(100);
  m.insert(80);
  m.insert(90);
  m.insert(75);
  m.insert(70);

  while (m.top() != -1) {
    cout << m.top() << endl;
    m.deleteFromHeap();
  }

  // vector<int> arr = { 54, 53, 55, 52, 50 };
  // int n = arr.size();

  // for (int i = (n / 2) - 1; i >= 0; i--) {
  //   maxHeapify(arr, i, n);
  // }

  // cout << "Max heap: " << endl;
  // for (int num : arr) {
  //   cout << num << ", ";
  // }

  // heapSort(arr);

  // cout << "\n\nSorted array:" << endl;
  // for (int num : arr) {
  //   cout << num << ", ";
  // }
  // cout << endl;

  // priority_queue<int> pq;
  // pq.push(100);
  // pq.push(80);
  // pq.push(95);
  // pq.push(70);
  // pq.push(75);
  // pq.push(85);
  // pq.push(50);

  // cout << pq.top() << endl;
  // pq.pop();
  // cout << pq.top() << endl;
  // pq.pop();
  // cout << pq.top() << endl;
}