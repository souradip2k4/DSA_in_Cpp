// https://leetcode.com/problems/lru-cache/description/
// 146. LRU Cache

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int key, val;
  Node *prev, *next;

  Node(int key, int val) {
    this->key = key;
    this->val = val;
    prev = nullptr;
    next = nullptr;
  }
};

class LRUCache {
public:
  Node *head = new Node(-1, -1);
  Node *tail = new Node(-1, -1);

  int capacity;
  unordered_map<int, Node *> uMap;

  Node *addNode(Node *node) {
    node->next = head->next;
    node->prev = head;
    head->next->prev = node;
    head->next = node;
    return node;
  }

  void deleteMiddleNode(Node *node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }

  void moveToHead(Node *node) {
    deleteMiddleNode(node);
    addNode(node);
  }


  int deleteLeastUsedKey() {
    Node *delNode = tail->prev;
    tail->prev->prev->next = tail;
    tail->prev = tail->prev->prev;
    int delKey = delNode->key;
    return delKey;
  }


  LRUCache(int capacity) {
    this->capacity = capacity;
    head->next = tail;
    tail->prev = head;
  }

  int get(int key) {
    if (uMap.find(key) != uMap.end()) {

      moveToHead(uMap[key]);
      return uMap[key]->val;
    }

    return -1;
  }

  void put(int key, int value) {
    if (uMap.find(key) != uMap.end()) {
      uMap[key]->val = value;
      moveToHead(uMap[key]);
    } else {
      if (capacity == uMap.size()) {
        int deletedKey = deleteLeastUsedKey();
        uMap.erase(deletedKey);
      }

      Node *node = new Node(key, value);
      node->key = key;
      node->val = value;
      uMap[key] = node;
      addNode(node);
    }
  }
};

int main() {
  LRUCache lru(2);
  lru.put(1, 1); // cache is {1=1}
  lru.put(2, 2); // cache is {1=1, 2=2}
  cout << lru.get(1) << endl; // return 1
  lru.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
  cout << lru.get(2) << endl; // returns -1 (not found)
  lru.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
  cout << lru.get(1) << endl; // return -1 (not found)
  cout << lru.get(3) << endl; // return 3
  cout << lru.get(4) << endl; // return 4
}
