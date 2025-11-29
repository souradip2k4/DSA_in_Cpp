// https://leetcode.com/problems/linked-list-cycle-ii/

#include <bits/stdc++.h>
#include<ListNode.h>

class Solution {
  public:
  ListNode* detectCycle(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
      return nullptr;
    }

    ListNode* slow = head, * fast = head;
    while (fast != nullptr) {
      if (fast->next == nullptr || fast->next->next == nullptr) {
        return nullptr;
      }

      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) {

        slow = head;
        while (fast != slow) {
          slow = slow->next;
          fast = fast->next;
        }

        return fast;
      }
    }

    return nullptr;
  }
};