// https://www.naukri.com/code360/problems/find-length-of-loop_8160455
#include <bits/stdc++.h>


class Node {
public:
    int data;
    Node *next;

    Node(int data) {
      this->data = data;
      this->next = NULL;
    }
};

int lengthOfLoop(Node *head) {
  if (head == nullptr || head->next == nullptr) {
    return 0;
  }

  Node *slow = head, *fast = head;

  while (fast != nullptr) {
    if (fast->next == nullptr || fast->next->next == nullptr) {
      return 0;
    }

    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) {

      slow = head;
      while (fast != slow) {

        slow = slow->next;
        fast = fast->next;
      }

      fast = fast->next;
      int count = 1; // Already 1 Node is calculated(Node before fast->next)
      while (fast != slow) {
        count++;
        fast = fast->next;
      }

      return count;
    }
  }

  return 0;
}
