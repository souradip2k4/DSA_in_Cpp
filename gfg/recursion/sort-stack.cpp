#include<bits/stdc++.h>
using namespace std;


stack<int> s;

/*void sortStack() {
  vector<int> arr;
  while (!s.empty()) {
    arr.push_back(s.top());
    s.pop();
  }
  vector<int> popElem;
  for (int num: arr) {
    if (s.empty()) {
      s.push(num);
    } else {
      if (num > s.top()) {
        s.push(num);
      } else {
        while (!s.empty() && num <= s.top()) {
          popElem.push_back(s.top());
          s.pop();
        }
        s.push(num);
      for (int i = popElem.size() - 1; i >= 0; i--) {
        s.push(popElem[i]);
      }
      }


      popElem.clear();
    }
  }

  while (!s.empty()) {
    cout << s.top() << ", ";
    s.pop();
  }
}*/

void sortStack() {
  vector<int> arr;
  while (!s.empty()) {
    arr.push_back(s.top());
    s.pop();
  }
  vector<int> popElem;
  for (int num: arr) {
    if (s.empty()) {
      s.push(num);
    } else {
      if (num > s.top()) {
        s.push(num);
      } else {
        while (!s.empty() && num <= s.top()) {
          popElem.push_back(s.top());
          s.pop();
        }
        s.push(num);
        for (int i = popElem.size() - 1; i >= 0; i--) {
          s.push(popElem[i]);
        }
      }


      popElem.clear();
    }
  }

  while (!s.empty()) {
    cout << s.top() << ", ";
    s.pop();
  }
}

int main() {
  s.push(11);
  s.push(2);
  s.push(32);
  s.push(3);
  s.push(41);

  /*s.push(3);
  s.push(2);
  s.push(1);*/
  sortStack();
}
