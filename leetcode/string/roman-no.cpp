// https://leetcode.com/problems/roman-to-integer/description/
// 13. Roman to Integer

#include <bits/stdc++.h>
using namespace std;

int romanToInt(string s) {
  if (s.size() < 1) {
    return 0;
  }
  unordered_map<char, int> uMap;
  uMap['I'] = 1;
  uMap['V'] = 5;
  uMap['X'] = 10;
  uMap['L'] = 50;
  uMap['C'] = 100;
  uMap['D'] = 500;
  uMap['M'] = 1000;
  int num = uMap[s[0]];
  char prev = s[0];
  for (int i = 1; i < s.size(); i++) {
    if (((s[i] == 'V' || s[i] == 'X') && prev == 'I')
        || ((s[i] == 'L' || s[i] == 'C') && prev == 'X')
        || ((s[i] == 'D' || s[i] == 'M') && prev == 'C')) {
      num += uMap[s[i]] - 2 * uMap[prev];
    } else {
      num += uMap[s[i]];
    }
    prev = s[i];
  }

  return num;
}

int main() {
  /*cout << romanToInt("III") << endl;
  cout << romanToInt("LVIII") << endl;
  cout << romanToInt("MCMXCIV") << endl;*/
  cout << romanToInt("IV") << endl;
}
