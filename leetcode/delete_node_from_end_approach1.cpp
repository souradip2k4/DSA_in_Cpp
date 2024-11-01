// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      int count = 0;
      ListNode *temp = head;

      while(temp != nullptr){
        count++;
        temp = temp->next;
      }

      ListNode *del;
      if(count == n){
        del = head;
        head = head->next;
        delete del;
        return head;
      }
      temp = head;

      for(int i = 1; i < count - n; i++){
        temp = temp->next;
      }

      del = temp->next;
      temp-> next = temp->next->next;
      delete del;
      return head;
    }
};