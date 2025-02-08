// 38. Count and Say
// https://leetcode.com/problems/count-and-say/description/

#include<bits/stdc++.h>
using namespace std;

string countAndSay(int n) {
  if (n == 1) return "1";

  string s = countAndSay(n - 1);
  string str = "";
  int count = 1;
  for (int i = 1; i < s.size(); i++) {
    if (s[i] == s[i - 1]) {
      count++;
    } else {
      str += to_string(count) + s[i-1];
      count = 1;
    }
  }

  str += to_string(count) + s.back();
  return str;
}

int main() {
  string r1 = countAndSay(5);

  cout << r1 << endl;
}
