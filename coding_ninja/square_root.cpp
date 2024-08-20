// https://www.naukri.com/code360/problems/square-root_893351
#include <iostream>
#include <cmath>

using namespace std;

long long int floorSqrt(long long int n) {
  long long int start = 0, end = n;
  long long int mid = start + (end - start) / 2;

  while (end > start) {
    long long int square = mid * mid;
    if (square < n && ((mid + 1) * (mid + 1) < n+1)) {
      start = mid + 1;
    } else if (square > n) {
      end = mid - 1;
    } else {
      return mid;
    }

    mid = start + (end - start) / 2;
  }

  return mid;
}

int main() {

  long long int root = floorSqrt(100);

  cout << "Square root: " << root << endl;
}