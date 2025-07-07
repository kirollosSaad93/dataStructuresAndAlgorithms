#include <iostream>

#include "LinkedList.h"
#include "DoublyLinkedList.h"

int main()
{
   LinkedList myList(10);
   Node* listHead = myList.getHead();
   if (listHead == nullptr)
   {
      std::cout << "List is empty! " << std::endl;
   }
   else
   {
      std::cout << "Head value is: " << listHead->value << std::endl;
   }
   myList.append(15);
   myList.append(20);
   myList.append(25);
   myList.append(30);
   myList.printList();
   myList.prepend(5);
   myList.printList();
   myList.removeLast();
   myList.printList();
   myList.removeIndex(0);
   myList.printList();
   myList.removeIndex(2);
   myList.printList();
   myList.getSize();
   myList.set(50, 3);
   myList.printList();


   DoublyLinkedList dll(5);
   dll.append(10);
   dll.append(15);
   dll.append(20);
   dll.append(25);
   dll.append(30);
   dll.append(35);
   dll.printList();
   dll.deleteFirst();
   dll.printList();
   dll.insert(0, 5);
   dll.printList();
   dll.deleteFirst();
   dll.set(0, 5);
   dll.printList();
   std::cout << "List size is: " << dll.getSize() << std::endl;
   Node* tempNode = dll.get(2);
   if (tempNode)
   {
      std::cout << "Returned Node value is: " << tempNode->value << std::endl;
   }
   else
   {
      std::cout << "Bad index or list is empty!" << std::endl;
   }

   dll.set(8, 50);
   dll.printList();

   dll.deleteIndex(2);
   dll.printList();

   dll.deleteLast();
   dll.printList();

   dll.insert(3, 50);
   dll.printList();
   return 0;
}