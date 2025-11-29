// https://leetcode.com/problems/merge-k-sorted-lists/
// 23. Merge k Sorted Lists

#include<bits/stdc++.h>
#include<ListNode.h>
using namespace std;

ListNode* mergeKLists(vector<ListNode*>& lists) {

  priority_queue<int, vector<int>, greater<int>> pq;

  for (ListNode* list : lists) {
    while (list) {
      pq.push(list->val);
      list = list->next;
    }
  }

  ListNode* head = NULL, * temp = NULL;

  while (!pq.empty()) {
    int value = pq.top();
    pq.pop();

    if (!head) {
      head = new ListNode(value);
    }
    else {
      temp->next = new ListNode(value);
      temp = temp->next;
    }
  }

  return head;
}