// https://leetcode.com/problems/odd-even-linked-list/description/
#include <bits/stdc++.h>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *oddEvenList(ListNode *head) {
      if (head == NULL || head->next == NULL) return head;

      ListNode *t1 = head, *t2 = head->next;
      ListNode *head2 = t2;
      while (t2 != nullptr && t2->next != nullptr) {
        t1->next = t2->next;
        t1 = t1->next;
        t2->next = t1->next;
        t2 = t2->next;
      }

      t1->next = head2;
      return head;
    }
};