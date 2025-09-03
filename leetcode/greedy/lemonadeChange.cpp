// https://leetcode.com/problems/lemonade-change/description/
// 860. Lemonade Change

#include<bits/stdc++.h>
using namespace std;

bool lemonadeChange(vector<int>& bills) {
  int five = 0, ten = 0, twenty = 0;

  for (int bill : bills) {
    if (bill == 5) {
      five++;
    }
    else if (bill == 10) {
      if (five) {
        five--;
        ten++;
      }
      else {
        return false;
      }
    }
    else {
      if (five && ten) {
        five--;
        ten--;
      }
      else if (five >= 3) {
        five -= 3;
      }
      else {
        return false;
      }
    }
  }

  return true;
}

int main() {
  int n;
  cin >> n;
  vector<int> bills(n);
  for (int& num : bills) {
    cin >> num;
  }

  cout << lemonadeChange(bills) << endl;
}