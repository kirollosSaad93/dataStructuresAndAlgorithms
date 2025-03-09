#include "SinglyLinkedList.h"
int main()
{
   LinkedList myList(5);
   myList.printList();
   myList.append(10);
   myList.printList();
   myList.append(15);
   myList.printList();
   myList.prepend(20);
   myList.printList();
   myList.insert(2, 25);
   myList.printList();
   myList.set(3,220);
   myList.printList();    
   myList.deleteLast();
   myList.deleteLast();
   myList.deleteLast();
   myList.deleteLast();
   myList.deleteLast();
   myList.printList();

   return 0;
}
