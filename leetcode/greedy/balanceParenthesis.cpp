#include<bits/stdc++.h>
using namespace std;

bool checkValidString(string s) {
  int low = 0, high = 0;


  for (char ch : s) {
    if (ch == '(') {
      low++;
      high++;
    }

    if (ch == ')') {
      if (low > 0) low--; // ch = '('
      high--;
    }

    if (ch == '*') {
      // if low = 0 that means now '(' exists in left side so * might be '' so we keep low as it is
      // if low > 0 that means '(' at left exists then we do low--
      if (low > 0) low--; // * = ')' or ''
      high++; // * = '('
    }

    if (high < 0) return false; // No of ')' > '('
  }

  return low == 0;

}

int main() {

  cout << checkValidString("(*))") << endl;
  cout << checkValidString("(*)") << endl;
  cout << checkValidString("())(") << endl; // if (high < 0) return false; is satisfied here 
}