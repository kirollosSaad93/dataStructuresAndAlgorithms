#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList(int value)
{
   head = new Node(value);
   tail = head;
   size++;
}

void DoublyLinkedList::append(int value)
{
   if (!head)
   {
      head = new Node(value);
      tail = head;
      size++;
   }
   else
   {
      Node* newNode = new Node(value);
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
      size++;
      std::cout << "Added Node of value: " << value << std::endl;
      std::cout << "Previous node is: " << newNode->prev->value << std::endl;
   }
}

void DoublyLinkedList::prepend(int value)
{
   if (head)
   {
      Node* newHead = new Node(value);
      newHead->next = head;
      head->prev = newHead;
      head = newHead;
      size++;
      std::cout << "Added new node as head! New head is: " << head->value << std::endl;
   }
   else
   {
      std::cout << "List is empty" << std::endl;
   }
}

void DoublyLinkedList::printList()
{
   if (!head)
   {
      std::cout << "List is empty" << std::endl;
   }
   else
   {
      Node* currentNode = head;
      std::cout << "[";
      while (currentNode)
      {
         if (!currentNode->next)
         {
            std::cout << currentNode->value << "]" << std::endl;
         }
         else
         {
            std::cout << currentNode->value << ", ";
         }
         currentNode = currentNode->next;
      }
   }
}

Node* DoublyLinkedList::get(int index)
{

   if (!head || index > size)
   {
      return nullptr;
   }
   else if (index == size)
   {
      return tail;
   }
   else if (index == 0)
   {
      return head;
   }
   else
   {
      if (index > (size - 1) / 2)
      {
         std::cout << "Greater Index!" << std::endl;
         Node* tempNode = tail;
         for (int i = size-1; i > ((size-1)/2); i--) //we already covered the tail case! start from size - 1 
         {
            std::cout << "Index is: " << index << ", and currentNode value is: " << tempNode->value << std::endl;
            if (index == i)
            {
               return tempNode;
            }
            else
            {
               tempNode = tempNode->prev;
            }
         }
      }
      else
      {
         std::cout << "Smaller Index!" << std::endl;
         Node* tempNode = head;
         for (int i = 0; i <= (size)/2; i++) // we already covered the head case! start from index 1
         {
            std::cout << "Index is: " << index << ", and currentNode value is: " << tempNode->value << std::endl;
            if (index == i)
            {
               return tempNode;
            }
            else
            {
               tempNode = tempNode->next;
            }
         }
      }
   }
   //should not get here!
   return nullptr;
}

void DoublyLinkedList::set(int index, int value)
{
   Node* tempNode = get(index);
   if (tempNode)
   {
      tempNode->value = value;
   }
   else
   {
      std::cout << "Bad Index or list is empty!" << std::endl;
   }
}

void DoublyLinkedList::insert(int index, int value)
{
   if (!head)
   {
      std::cout << "List is empty! Setting index 0 to value: " << value << std::endl;
      head = new Node(value);
   }
   else if (index == 0)
   {
      prepend(value);
   }
   else if (index == size)
   {
      append(value);
   }
   else
   {
      Node* nextNode = get(index);
      Node* prevNode = nextNode->prev;
      std::cout << "Inserting new node of value: " << value << " between: " << prevNode->value << ", and " << nextNode->value <<  std::endl;
      Node* newNode = new Node(value);
      newNode->prev = prevNode;
      newNode->next = nextNode;
      prevNode->next = newNode;
      nextNode->prev = newNode;
      size++;
   }

}

void DoublyLinkedList::deleteFirst()
{
   if (head)
   {
      Node* newHead = head->next;
      newHead->prev = nullptr;
      delete head;
      head = newHead;
      size--;
      std::cout << "Deleted head! New head is: " << head->value << std::endl;
   }
   else
   {
      std::cout << "List is empty" << std::endl;
   }
}

void DoublyLinkedList::deleteLast()
{
   if (!head)
   {
      std::cout << "List is empty" << std::endl;
   }
   else if (head == tail)
   {
      delete head;
      delete tail;
      size--;
   }
   else
   {
      Node* newTail = tail->prev;
      newTail->next = nullptr;
      delete tail;
      tail = newTail;
      size--;
      std::cout << "Removed Tail! New tail is: " << tail->value << std::endl;
   }
   
}

void DoublyLinkedList::deleteIndex(int index)
{
   if (!head)
   {
      std::cout << "List is empty" << std::endl;
   }
   else if (head == tail)
   {
      delete head;
      delete tail;
      size--;
      std::cout << "List is empty" << std::endl;
   }
   else
   {
      Node* tempNode = get(index);
      Node* beforeNode = tempNode->prev;
      Node* afterNode = tempNode->next;
      afterNode->prev = beforeNode;
      beforeNode->next = afterNode;
      delete tempNode;
      size--;
      std::cout << "Deleted node at index: " << index << std::endl;
   }
}

