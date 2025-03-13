// https://www.geeksforgeeks.org/problems/insert-a-node-in-doubly-linked-list/1
#include <bits/stdc++.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;

    Node(int x) {
      data = x;
      next = prev = NULL;
    }
};

class Solution {
public:
    Node *addNode(Node *head, int pos, int data) {
      if (head == nullptr) {
        return head;
      }


      Node *temp = head;
      for (int i = 0; i < pos && temp != nullptr; i++) {
        temp = temp->next;
      }

      if (temp == nullptr) {
        return head;
      }

      Node *newN = new Node(data);

      if (temp->next == nullptr) {
        temp->next = newN;
        newN->prev = temp;
      } else {
        newN->next = temp->next;
        newN->prev = temp;
        newN->next->prev = newN;
        temp->next = newN;

      }


      return head;

    }
};