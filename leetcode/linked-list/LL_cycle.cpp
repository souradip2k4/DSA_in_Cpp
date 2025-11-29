// https://leetcode.com/problems/linked-list-cycle/description/
#include <bits/stdc++.h>
#include<ListNode.h>

class Solution {
  public:
  bool hasCycle(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
      return false;
    }

    ListNode* slow = head, * fast = head->next;
    // fast = head->next to prevent the loop from terminating at the beginning
    while (fast != slow) {
      if (fast->next == nullptr || fast->next->next == nullptr) {
        return false;
      }
      slow = slow->next;
      fast = fast->next->next;

    }

    return true;
  }
};