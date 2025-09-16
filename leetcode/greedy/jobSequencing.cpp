// https://www.naukri.com/code360/problems/job-sequencing-problem_1169460
// Job Sequencing Problem

#include<bits/stdc++.h>
using namespace std;

bool comparator(vector<int>& a, vector<int>& b) {
  return a[2] > b[2];
}


vector<int> jobScheduling(vector<vector<int>>& jobs)
{
  sort(jobs.begin(), jobs.end(), comparator);
  int n = jobs.size();

  int maxDeadline = 0;

  for (int i = 0; i < n; i++) {
    maxDeadline = max(maxDeadline, jobs[i][1]);
  }

  int profit = 0, jobCnt = 0;

  vector<int> arr(maxDeadline, -1);

  for (int i = 0; i < jobs.size(); i++) {
    int index = jobs[i][1] - 1;

    int j = index;
    while (j >= 0) {
      if (arr[j] == -1) {
        arr[j] = jobs[i][0];
        profit += jobs[i][2];
        jobCnt++;
        break;
      }

      j--;
    }
  }

  return { jobCnt, profit };
}


