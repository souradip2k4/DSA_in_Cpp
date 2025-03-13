// https://leetcode.com/problems/linked-list-cycle/description/
#include <bits/stdc++.h>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
      if (head == nullptr || head->next == nullptr) {
        return false;
      }

      ListNode *slow = head, *fast = head->next;
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