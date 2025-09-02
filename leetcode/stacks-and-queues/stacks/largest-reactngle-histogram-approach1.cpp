// https://leetcode.com/problems/largest-rectangle-in-histogram/
// 84. Largest Rectangle in Histogram
// O(5n)

#include <values.h>
#include <bits/stdc++.h>
using namespace std;

vector<int> prevSmallestElem(vector<int> &heights)
{
  stack<int> st;
  int n = heights.size();
  vector<int> pse(n);

  // O(n)
  for (int i = 0; i < n; i++)
  {
    // O(n)
    while (!st.empty() && heights[i] <= heights[st.top()])
    {
      st.pop();
    }

    if (!st.empty())
    {
      pse[i] = st.top();
    }
    else
    {
      pse[i] = -1;
    }

    st.push(i);
  }

  return pse;
}

vector<int> nextSmallestElem(vector<int> &heights)
{
  stack<int> st;
  int n = heights.size();
  vector<int> nse(n);

  // O(n)
  for (int i = n - 1; i >= 0; i--)
  {
    // O(n)
    while (!st.empty() && heights[i] <= heights[st.top()])
    {
      st.pop();
    }

    if (!st.empty())
    {
      nse[i] = st.top();
    }
    else
    {
      nse[i] = n;
    }

    st.push(i);
  }

  return nse;
}

int largestRectangleArea(vector<int> &heights)
{
  vector<int> pse = prevSmallestElem(heights);
  vector<int> nse = nextSmallestElem(heights);
  int maxArea = MININT;

  // O(n)
  for (int i = 0; i < heights.size(); i++)
  {
    maxArea = max(maxArea, heights[i] * (nse[i] - pse[i] - 1));
  }

  return maxArea;
}

int main()
{
  vector<int> arr1 = {2, 1, 5, 6, 2, 3};
  vector<int> arr2 = {2, 4};

  cout << largestRectangleArea(arr1) << endl;
  cout << largestRectangleArea(arr2) << endl;
}
