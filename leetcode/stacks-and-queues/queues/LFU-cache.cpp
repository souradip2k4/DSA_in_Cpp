// https://leetcode.com/problems/lfu-cache/description/
// 460. LFU Cache

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int key, val, freq;
  Node *prev, *next;

  Node(int key, int val) {
    this->key = key;
    this->val = val;
    this->freq = 1;
    prev = nullptr;
    next = nullptr;
  }
};

class List {
public:
  Node *head, *tail;
  int size;

  List() {
    head = new Node(-1, -1);
    tail = new Node(-1, -1);
    head->next = tail;
    tail->prev = head;
    size = 0;
  }

  void addNode(Node *node) {
    node->next = head->next;
    node->prev = head;
    head->next->prev = node;
    head->next = node;
    size++;
  }

  void deleteNode(Node *node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
    size--;
  }

  Node *removeLast() {
    if (size > 0) {
      Node *delNode = tail->prev;
      deleteNode(delNode);
      return delNode;
    }
    return nullptr;
  }
};

class LFUCache {
public:
  int capacity, minFreq;
  unordered_map<int, Node *> keyNode;
  unordered_map<int, List *> freqList;

  LFUCache(int capacity) {
    this->capacity = capacity;
    this->minFreq = 0;
  }

  void updateFreq(Node *node) {
    int freq = node->freq;
    freqList[freq]->deleteNode(node);
    if (freqList[freq]->size == 0 && freq == minFreq) {
      freqList.erase(freq);
      minFreq++;
    }

    node->freq++;
    if (!freqList.count(node->freq)) {
      freqList[node->freq] = new List();
    }
    freqList[node->freq]->addNode(node);
  }

  int get(int key) {
    if (keyNode.find(key) == keyNode.end()) return -1;
    Node *node = keyNode[key];
    updateFreq(node);
    return node->val;
  }

  void put(int key, int value) {
    if (capacity == 0) return;

    if (keyNode.find(key) != keyNode.end()) {
      Node *node = keyNode[key];
      node->val = value;
      updateFreq(node);
      return;
    }

    if (keyNode.size() == capacity) {
      Node *delNode = freqList[minFreq]->removeLast();
      keyNode.erase(delNode->key);
      delete delNode;
    }

    minFreq = 1;
    Node *newNode = new Node(key, value);
    if (!freqList.count(1)) {
      freqList[1] = new List();
    }
    freqList[1]->addNode(newNode);
    keyNode[key] = newNode;
  }
};

int main() {
  LFUCache cache(2);
  cache.put(1, 1);
  cache.put(2, 2);
  cout << cache.get(1) << endl; // 1
  cache.put(3, 3); // Evicts key 2
  cout << cache.get(2) << endl; // -1
  cout << cache.get(3) << endl; // 3
}
