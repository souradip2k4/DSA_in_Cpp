// https://leetcode.com/problems/count-good-numbers/
// 1922. Count Good Numbers

#include<bits/stdc++.h>
using namespace std;

long long MOD = 1000000007;

long long powerCalc(long long x, long long power) {
  if (power == 0) return 1;

  long long temp = powerCalc(x, power / 2);

  if (power % 2 == 0) {
    return (temp * temp)%MOD;
  } else {
    return (x * temp * temp)% MOD;
  }

}

int countGoodNumbers(long long n) {
  long long evenPlaces = (n + 1) / 2;
  long long oddPlaces = n / 2;
  long long first = powerCalc(5, evenPlaces) % MOD;
  long long second = powerCalc(4, oddPlaces) % MOD;
  // cout << first << ", "<< second << endl;
  return (int)((first * second) % MOD);
}

int main() {
  cout << countGoodNumbers(1) << endl;
  cout << countGoodNumbers(4) << endl;
  cout << countGoodNumbers(5) << endl;
  cout << countGoodNumbers(50) << endl;
}
