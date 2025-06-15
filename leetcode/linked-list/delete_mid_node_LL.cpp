// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
#include <bits/stdc++.h>
using namespace std;

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
  ListNode *deleteMiddle(ListNode *head) {
    if (head == nullptr && head->next == nullptr) {
      return nullptr;
    }

    ListNode *slow = head, *fast = head->next;

    while (fast->next != nullptr && fast->next->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode *del = slow->next;
    slow->next = slow->next->next;
    delete del;
    return head;
  }
};
