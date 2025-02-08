// 686. Repeated String Match
// https://leetcode.com/problems/repeated-string-match/description/

#include<bits/stdc++.h>
using namespace std;

int repeatedStringMatch(string a, string b) {
  string str;
  int count = 0, minRepeat = ceil((double) b.size() / a.size()); // Minimum repetitions required to cover 'b'

  while (str.find(b) == -1) {
    str += a;
    count++;
    // If we have already exceeded the minimum required repetitions + 1 and still can't find 'b',
    // then it's impossible to form 'b' by repeating 'a'. Return -1.
    if (count > minRepeat + 1) {
      return -1;
    }
  }

  return count;
}

int main() {
  int r1 = repeatedStringMatch("abcd", "cdabcdab");
  int r2 = repeatedStringMatch("a", "aa");

  cout << r1 << endl;
}
