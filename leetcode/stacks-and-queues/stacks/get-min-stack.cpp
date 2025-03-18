// https://leetcode.com/problems/min-stack/
// 155. Min Stack

#include<bits/stdc++.h>
using namespace std;

class MinStack {
public:
  stack<pair<int, int> > s;
  int minVal = INT_MAX;

  MinStack() {}

  void push(int val) {
    minVal = !s.empty() ? min(val, s.top().second) : val;
    s.push({val, minVal});
  }

  void pop() {
    if (!s.empty()) {
      s.pop();
    }
  }

  int top() {
    return !s.empty() ? s.top().first : -1;
  }

  int getMin() {
    return !s.empty() ? s.top().second : -1;
  }
};

int main() {
  MinStack minStack;
  minStack.push(-2);
  minStack.push(0);
  minStack.push(-3);
  cout << minStack.getMin() << endl; // return -3
  minStack.pop();
  minStack.top(); // return 0
  cout << minStack.getMin() << endl; // return -2
}
