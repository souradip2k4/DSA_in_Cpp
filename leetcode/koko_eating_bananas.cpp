// https://leetcode.com/problems/koko-eating-bananas/description/
#include <bits/stdc++.h>

using namespace std;

int calcSpeed(vector<int> &piles, int max, int hour) {


  int l = 1, h = max, mid, totHrs = 0;
  mid = l + (h - l) / 2;

  while (l <= h) {
    totHrs = 0;
    for (auto elem: piles) {
      totHrs += ceil((double) elem / mid);
    }

    if (totHrs <= hour) {
      h = mid - 1;
    } else {
      l = mid + 1;
    }

    mid = l + (h - l) / 2;
  }

  return mid;
}

int minEatingSpeed(vector<int> &piles, int hour) {
  int minSpeed, max = piles[0];

  for (int elem: piles) {
    if (elem > max) {
      max = elem;
    }
  }

  minSpeed = calcSpeed(piles, max, hour);

  return minSpeed;
}

int main() {
  vector<int> pileArr1 = {30, 11, 23, 4, 20};
  vector<int> pileArr2 = {1, 1, 1, 999999999};

  int minSpeed = minEatingSpeed(pileArr2, 10);

  cout << minSpeed << endl;
}