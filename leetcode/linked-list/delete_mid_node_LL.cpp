// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
#include <bits/stdc++.h>
#include<ListNode.h>
using namespace std;

class Solution {
  public:
  ListNode* deleteMiddle(ListNode* head) {
    if (head == nullptr && head->next == nullptr) {
      return nullptr;
    }

    ListNode* slow = head, * fast = head->next;

    while (fast->next != nullptr && fast->next->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode* del = slow->next;
    slow->next = slow->next->next;
    delete del;
    return head;
  }
};
