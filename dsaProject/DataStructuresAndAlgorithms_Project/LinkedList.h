#pragma once
/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include "Node.h"
class LinkedList
{
public:
   LinkedList(int value);

   Node* getHead()
   {
      return head;
   }

   void append(int value);

   void printList();

   void prepend(int value);

   int getSize();

   void removeHead();

   void removeLast();

   void removeIndex(int index);

   void set(int value, int index);

   //Node* reverse();

private:
   Node* head;
   Node* tail;
   int size;
};

