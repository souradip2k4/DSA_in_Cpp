// https://leetcode.com/problems/online-stock-span/
// 901. Online Stock Span

#include<bits/stdc++.h>
using namespace std;

class StockSpanner {
public:
  stack<pair<int, int> > st;

  StockSpanner() {
  }

  int next(int price) {
    pair<int, int> elem = {price, 1};
    if (st.empty()) {
      st.push(elem);
    } else {
      if (price < st.top().first) {

        st.push(elem);
      } else {

        while (!st.empty() && price >= st.top().first) {
          elem.second += st.top().second;
          st.pop();
        }

        st.push(elem);
      }
    }

    return elem.second;
  }
};


int main() {
  StockSpanner *stockSpanner = new StockSpanner();
  cout << stockSpanner->next(100) << endl; // return 1
  cout << stockSpanner->next(80) << endl; // return 1
  cout << stockSpanner->next(60) << endl; // return 1
  cout << stockSpanner->next(70) << endl; // return 2
  cout << stockSpanner->next(60) << endl; // return 1
  cout << stockSpanner->next(75) << endl;
  // return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.
  cout << stockSpanner->next(85) << endl; // return 6
}
