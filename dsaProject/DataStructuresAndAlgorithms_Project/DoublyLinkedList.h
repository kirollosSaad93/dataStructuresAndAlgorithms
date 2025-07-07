#pragma once
#include <iostream>

#include "Node.h"

class DoublyLinkedList
{
   private:
      Node* head;
      Node* tail;
      int size;

   public:
      DoublyLinkedList(int value);

      void append(int value);

      void printList();

      void prepend(int value);
      
      Node* get(int index);

      void set(int index, int value);

      void insert(int index, int value);

      int getSize() { return size; }

      void deleteFirst();

      void deleteLast();

      void deleteIndex(int index);

};

