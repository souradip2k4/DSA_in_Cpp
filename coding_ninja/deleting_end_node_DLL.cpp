// https://www.naukri.com/code360/problems/delete-last-node-of-a-doubly-linked-list_8160469
#include <bits/stdc++.h>

struct Node {
    int data;
    Node *prev;
    Node *next;

    Node() : data(0), prev(nullptr), next(nullptr) {}

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}

    Node(int val, Node *p, Node *n) : data(val), prev(p), next(n) {}
};


Node *deleteLastNode(Node *head) {
  if (head == nullptr || head->next == nullptr) {
    return nullptr;
  }

  Node *temp = head;
  while (temp->next->next != nullptr) {
    temp = temp->next;
  }

  Node *del = temp->next;
  temp->next = nullptr;
  free(del);
  return head;
}
