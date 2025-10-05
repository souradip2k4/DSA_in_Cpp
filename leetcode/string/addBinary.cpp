// https://leetcode.com/problems/add-binary/
// 67. Add Binary

#include<bits/stdc++.h>
using namespace std;

string addBinary(string a, string b) {
  int carry = 0;

  if (b.size() > a.size()) swap(a, b);

  int i = a.size() - 1;
  int j = b.size() - 1;
  string op = "";

  while (j >= 0) {
    int bitA = a[i] - '0';
    int bitB = b[j] - '0';
    int sum = bitA + bitB;

    if (sum == 0) {
      op += carry == 1 ? "1" : "0";
      carry = 0;
    }
    else if (sum == 1) {
      if (carry == 1) {
        op += "0";
        carry = 1;
      }
      else {
        op += "1";
        carry = 0;
      }
    }
    else if (sum == 2) {
      op += carry == 1 ? "1" : "0";
      carry = 1;
    }

    i--;
    j--;
  }

  while (i >= 0) {
    int bitA = a[i] - '0';

    if (bitA == 0) {
      op += carry == 1 ? "1" : "0";
      carry = 0;
    }
    else {
      if (carry == 1) {
        op += "0";
        carry = 1;
      }
      else {
        op += "1";
        carry = 0;
      }
    }

    i--;
  }

  if (carry == 1) {
    op += "1";
  }

  reverse(op.begin(), op.end());
  return op;
}