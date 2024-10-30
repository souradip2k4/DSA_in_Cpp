// https://www.naukri.com/code360/problems/reverse-a-doubly-linked-list_1116098
#include <bits/stdc++.h>

class Node
{
public:
    int data;
    Node *next,*prev;
    Node()
    {
        this->data = 0;
        next = NULL;
        prev= NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev= NULL;
    }
    Node(int data, Node* next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev= prev;
    }
};



Node* reverseDLL(Node* head)
{
  if(head == NULL || head->next == NULL){
    return head;
  }


  Node *temp = head;
  Node *back = NULL;

  while(temp != NULL){
    back = temp->prev;
    temp->prev = temp->next;
    temp->next = back;


    temp = temp->prev;
  }

  return back->prev;
}
