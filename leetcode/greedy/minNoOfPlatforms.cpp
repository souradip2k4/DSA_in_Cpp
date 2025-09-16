// https://www.naukri.com/code360/problems/minimum-number-of-platforms_799400

// Minimum Number of Platforms

#include<bits/stdc++.h>
using namespace std;


// Brute force approach
/*
int calculateMinPatforms(int at[], int dt[], int n) {

  vector<pair<int, int>> arr;
  for (int i = 0; i < n; i++) {
    arr.push_back({ at[i], dt[i] });

  }

  sort(arr.begin(), arr.end());

  vector<pair<int, int>> ans;

  ans.push_back({ arr[0].first, arr[0].second });

  for (int i = 1; i < n; i++) {
    bool placed = false;

    for (int j = 0; j < ans.size(); j++) {
      if (ans[j].second < arr[i].first) {
        ans[j] = { arr[i].first,arr[i].second };
        placed = true;
        break;
      }
    }

    if (!placed) {
      ans.push_back({ arr[i].first, arr[i].second });
    }

  }

  return ans.size();
} */


// OPtimal approach
int calculateMinPatforms(int at[], int dt[], int n) {

  sort(at, at + n);
  sort(dt, dt + n);

  int i = 1, j = 0;
  int cnt = 1, maxCnt = 1;
  while (i < n && j < n) {
    if (at[i] <= dt[j]) {
      cnt++;
      i++;
    }
    else {
      cnt--;
      j++;
    }

    maxCnt = max(cnt, maxCnt);

  }

  return maxCnt;
}



int main() {
  int n;
  cin >> n;

  int at[n], dt[n];
  for (int i = 0; i < n; i++) {
    cin >> at[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> dt[i];
  }

  cout << calculateMinPatforms(at, dt, n) << endl;
}