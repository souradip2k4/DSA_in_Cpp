// https://leetcode.com/problems/reverse-linked-list/
#include <bits/stdc++.h>

struct ListNode {
  int val;
  ListNode *next;

  ListNode() : val(0), next(nullptr) {
  }

  ListNode(int x) : val(x), next(nullptr) {
  }

  ListNode(int x, ListNode *next) : val(x), next(next) {
  }
};

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    ListNode *temp = head, *front;
    ListNode *prev = nullptr;

    while (temp != nullptr) {
      front = temp->next;
      temp->next = prev;
      prev = temp;
      temp = front;
    }
    head = prev;

    return head;
  }
};
