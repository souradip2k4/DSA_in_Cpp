// https://leetcode.com/problems/palindrome-linked-list/submissions/1439838455/
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
    bool isPalindrome(ListNode *head) {

      ListNode *slow = head, *fast = head;

      while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
      }

      ListNode *temp = head;
      while (temp->next != nullptr) {
        temp = temp->next;
      }

      ListNode *prev = nullptr, *curr = slow, *front;
      while (curr != nullptr) {
        front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
      }

      ListNode *firstPrt = head, *secondPrt = prev;
      while (secondPrt != nullptr) {
        if (firstPrt->val != secondPrt->val) {
          return false;
        }

        firstPrt = firstPrt->next;
        secondPrt = secondPrt->next;
      }


      return true;
    }
};
