int main() 
{
   DLL myDLL(5);
   myDLL.printList();
   myDLL.append(10);
   myDLL.printList();
   myDLL.append(20);
   myDLL.printList();
   myDLL.append(25);
   myDLL.printList();
   myDLL.prepend(0);
   myDLL.printList();
   myDLL.insert(4, 15); //insert at a random index
   myDLL.printList();
   myDLL.insert(1, -5); // insert at head
   myDLL.printList();
   myDLL.insert(7, 50); //insert at tail
   myDLL.printList();
   
   myDLL.getByIndex(7);
   myDLL.getByValue(20);
   myDLL.set(8,30);
   myDLL.printList();

   myDLL.deleteFirst();
   myDLL.printList();
   myDLL.deleteLast();
   myDLL.printList();
   myDLL.deleteLast();
   myDLL.printList();
   myDLL.deleteLast();
   myDLL.printList();
   myDLL.deleteLast();
   myDLL.printList();
   return 0;
}
