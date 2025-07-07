#pragma once
class Node
{
public:
   Node(int value)
   {
      this->value = value;
      next = nullptr;
      prev = nullptr;
   }
   int value;
   Node* next;
   Node* prev; //Not utilized in signly linked list
};
