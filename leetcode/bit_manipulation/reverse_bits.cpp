// https://leetcode.com/problems/reverse-bits/description/?envType=problem-list-v2&envId=a0pb9aqc
// 190. Reverse Bits
#include <bits/stdc++.h>
using namespace std;

uint32_t reverseBits(uint32_t n) {
  uint32_t res = 0;
  for (int i = 31; i >= 0; i--) {
    uint32_t bit = n & 1; // Extracting the LSB
    n = n >> 1; // Right shift n by 1 so 1th bit becomes 0th bit
    res = res | (bit << i); // Appending the extracted LSB to the MSB of the new number
  }

  return res;
}

int main() {
  uint32_t a = 0b00000010100101000001111010011100;
  uint32_t b = reverseBits(a);

  cout << b << endl;
}
