// https://leetcode.com/problems/reverse-nodes-in-k-group/description

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


ListNode *reverseKGroup(ListNode *head, int k) {
  if (head == nullptr || head->next == nullptr || k == 1) {
    return head;
  }

  int count = 0;
  ListNode *temp = head;
  ListNode *temp2;
  ListNode *prev = nullptr;
  ListNode *front;
  ListNode *target = head;
  ListNode *headCopy = head;

  ListNode *refNode = nullptr;

  while (temp != nullptr) {
    count = 0;
    // First, find the k-th node without advancing the main `temp` iterator yet.
    ListNode *k_th_node = target;
    while (k_th_node != nullptr && count < k) {
      k_th_node = k_th_node->next;
      count++;
      count++;
    }

    // If we found a full group of k nodes
    if (count == k) {
      // The reversal loop needs a stable boundary.
      // `k_th_node` (which is temp->next from the original logic) is that boundary.
      prev = k_th_node; // The new tail will point to the start of the next group.
      temp2 = target;

      // Reverse the k nodes from `target` up to (but not including) `k_th_node`.
      while (temp2 != k_th_node) {
        front = temp2->next;
        temp2->next = prev;
        prev = temp2;
        temp2 = front;
      }

      // Now `prev` is the new head of the reversed group.
      // Connect the previous part of the list to this new head.
      if (target == headCopy) {
        head = prev;
      } else {
        refNode->next = prev;
      }

      // The original head of the group (`target`) is now the tail.
      // It becomes the reference node for the next group's connection.
      refNode = target;

      // Advance pointers for the next iteration.
      // Both `target` and `temp` must jump to the start of the next group.
      target = k_th_node;
      temp = k_th_node;
    } else {
      // Not enough nodes left, so we are done.
      break;
    }
  }

  return head;
}
