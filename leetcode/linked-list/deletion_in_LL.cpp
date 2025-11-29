// https://leetcode.com/problems/delete-node-in-a-linked-list/description/

#include <bits/stdc++.h>
#include<ListNode.h>
using namespace std;

class Solution {
  public:
  void deleteNode(ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
  }
};