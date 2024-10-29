#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int data) {
      this->data = data;
      this->next = nullptr;
    }
};

class LinkedList {
public:
    Node *head;

public:
    LinkedList() {
      head = nullptr;
    }

    bool checkEmptyList() {
      if (!head) {
        return true;
      } else {
        return false;
      }
    }

    void insertAtBeginning(int val) {
      Node *newNode = new Node(val);
      head = newNode;
    }

    void insertAtEnd(int val) {
      Node *newNode = new Node(val);

      if (checkEmptyList()) {
        head = newNode;
        return;
      }

      Node *temp = head;

      while (temp->next != nullptr) {
        temp = temp->next;
      }

      temp->next = newNode;
    }

    void insertAtPosition(int pos, int val) {
      if (pos < 0) {
        cout << "Position should be >= 0" << endl;
        return;
      } else if (pos == 0) {
        insertAtBeginning(val);
      } else {
        Node *newNode = new Node(val);

        Node *temp = head;
        for (int i = 0; i < pos - 1 && temp; i++) {
          temp = temp->next;
        }

        if (!temp) {
          cout << "Position out of range " << endl;
          return;
        }

        newNode->next = temp->next; // Before
        temp->next = newNode;
      }

    }

    void deleteFromBeginning() {
      if (checkEmptyList()) {
        cout << "List is empty " << endl;
        return;
      }

      Node *temp = head;
      head = head->next;
      free(temp);
    }

    void deleteFromEnd() {
      if (checkEmptyList()) {
        cout << "List is empty " << endl;
        return;
      }

      Node *temp = head;
      while (temp->next->next) {
        temp = temp->next;
      }

      free(temp->next);
      temp->next = nullptr;
    }

    void deleteFromPosition(int pos) {

      if (pos < 0) {
        cout << "Position should be >= 0" << endl;
        return;
      } else if (pos == 0) {
        deleteFromBeginning();
        return;
      } else {

        Node *temp = head;
        for (int i = 0; i < pos - 1 && temp; i++) {
          temp = temp->next;
        }

        if (!temp || !temp->next) {
          cout << "Position out of range " << endl;
          return;
        }

        Node *delNode = temp->next;
        temp->next = temp->next->next;
        free(delNode);

      }

    }

    void display() {
      if (!head) {
        cout << "List is empty " << endl;
      }

      Node *temp = head;
      while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
      }
      cout << "null" << endl;
    }
};

int main() {

  LinkedList list1;

  list1.insertAtEnd(10);
  list1.insertAtEnd(20);
  list1.insertAtEnd(30);
  list1.insertAtEnd(40);

  list1.display();
  list1.deleteFromPosition(3);
//  list1.deleteFromEnd();
  list1.display();

  list1.insertAtPosition(3, 60);
  list1.display();
}