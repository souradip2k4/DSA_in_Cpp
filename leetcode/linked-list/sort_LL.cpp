// https://leetcode.com/problems/sort-list/description/
// 148. Sort List

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

void merge(ListNode *head, ListNode *mid, ListNode *tail) {
  ListNode *left = head, *m = mid, *right = mid->next, *high = tail->next;

  ListNode *node = new ListNode(-1, nullptr);
  ListNode *nodeHead = node;
  while (left != m->next && right != high) {
    if (left->val < right->val) {
      node->next = new ListNode(left->val, nullptr);
      node = node->next;
      left = left->next;
    } else {
      node->next = new ListNode(right->val, nullptr);
      node = node->next;
      right = right->next;
    }
  }

  while (left != m->next) {
    node->next = new ListNode(left->val, nullptr);
    node = node->next;
    left = left->next;
  }

  while (right != high) {
    node->next = new ListNode(right->val, nullptr);
    node = node->next;
    right = right->next;
  }

  ListNode *temp = head;
  nodeHead = nodeHead->next;
  while (temp != high) {
    temp->val = nodeHead->val;
    temp = temp->next;
    nodeHead = nodeHead->next;
  }
}

void mergeSort(ListNode *head, ListNode *tail) {
  if (head == tail || head == nullptr) {
    return;
  }

  ListNode *slow = head, *fast = head;

  while (fast != tail && fast->next != tail) {
    slow = slow->next;
    fast = fast->next->next;
  }

  mergeSort(head, slow);
  mergeSort(slow->next, tail);
  merge(head, slow, tail);
}

ListNode *sortList(ListNode *head) {
  if (!head || !head->next) return head;
  ListNode *temp = head;

  while (temp->next != nullptr) {
    temp = temp->next;
  }

  mergeSort(head, temp);

  return head;
}
