// https://leetcode.com/problems/implement-stack-using-queues/
// 225. Implement Stack using Queues

#include <bits/stdc++.h>
using namespace std;

class MyStack {
  queue<int> q1, q2;
public:
  MyStack() {}

  void push(int x) {
    q2.push(x);

    while (!q1.empty()) {
      q2.push(q1.front());
      q1.pop();
    }

    q1.swap(q2);
  }

  int pop() {
    int n = q1.front();
    q1.pop();
    return n;
  }

  int top() {
    return q1.front();
  }

  bool empty() {
    return  q1.empty();
  }
};

int main() {
  MyStack myStack;
  myStack.push(1);
  myStack.push(2);
  cout <<  myStack.top() << endl; // return 2
  cout << myStack.pop() << endl; // return 2
  cout << myStack.empty() << endl; // return false
}