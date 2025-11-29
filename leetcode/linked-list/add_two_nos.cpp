// https://leetcode.com/problems/add-two-numbers/description/

#include <bits/stdc++.h>
#include<ListNode.h>
using namespace std;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  int count1 = 0, count2 = 0;
  ListNode* temp;

  temp = l1;
  while (temp != nullptr) {
    count1++;
    temp = temp->next;
  }

  temp = l2;
  while (temp != nullptr) {
    count2++;
    temp = temp->next;
  }

  ListNode* temp1, * temp2, * head;
  if (count1 > count2) {
    temp1 = l1;
    temp2 = l2;
    head = l1;
  }
  else {
    temp1 = l2;
    temp2 = l1;
    head = l2;
  }

  int carry = 0;
  ListNode* tail = nullptr;
  while (temp1 != nullptr) {
    int sum = 0;
    if (temp1->next == nullptr) {
      tail = temp1;
    }

    if (temp2 != nullptr) {
      sum = (temp1->val + temp2->val + carry);
      carry = sum >= 10 ? 1 : 0;

      temp1->val = sum % 10;

      temp1 = temp1->next;
      temp2 = temp2->next;
    }
    else {
      sum = temp1->val + carry;
      temp1->val = sum % 10;
      carry = sum >= 10 ? 1 : 0;

      temp1 = temp1->next;
    }
  }

  if (tail != nullptr && carry == 1) {
    tail->next = new ListNode(1);
  }

  return head;
}
