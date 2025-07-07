#include "LinkedList.h"

LinkedList::LinkedList(int value)
{
   if (!head)
   {
      head = new Node(value);
      tail = head;
      size++;
      std::cout << "Added head with value of: " << head->value << std::endl;
   }
}

void LinkedList::append(int value)
{
   if (!head)
   {
      //should not happen
      head = new Node(value);
      size++;
   }
   else
   {
      Node* currentNode = head;
      while (currentNode)
      {
         if (!currentNode->next)
         {
            break;
         }
         else
         {
            currentNode = currentNode->next;
         }
      }
      Node* newNode = new Node(value);
      currentNode->next = newNode;
      tail = newNode;
      size++;
      std::cout << "Added item to list with value of: " << currentNode->next->value << std::endl;
   }
}

void LinkedList::printList()
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

void LinkedList::prepend(int value)
{
   if (!head)
   {
      head = new Node(value);
      size++;
      std::cout << "Added head with value of: " << head->value << std::endl;
   }
   else
   {
      Node* newHead = new Node(value);
      newHead->next = head;
      head = newHead;
      size++;
      std::cout << "Changed head to value of: " << head->value << std::endl;
   }
}

int LinkedList::getSize()
{
   std::cout << "LinkedList Size is: " << this->size << std::endl;
   return this->size;
}

void LinkedList::removeHead()
{
   if (!head)
   {
      std::cout << "List is empty" << std::endl;
   }
   else
   {
      if (head->next == nullptr)
      {
         delete head;
         size--;
         std::cout << "Removing head. List is not empty!" << std::endl;
      }
      else
      {
         Node* newHead = head->next;
         delete head;
         head = newHead;
         std::cout << "Removing head. New head is now: " << head->value << std::endl;
         this->size--;
      }
   }
}

void LinkedList::removeLast()
{
   if (!head)
   {
      std::cout << "List is empty" << std::endl;
   }
   else
   {
      Node* currentNode = head;
      Node* prevNode = head;
      while (currentNode)
      {
         if (!currentNode->next)
         {
            prevNode->next = nullptr;
            tail = prevNode->next;
            std::cout << "removing last node of value: " << currentNode->value << std::endl;
            delete currentNode;
            size--;
            break;
         }
         else
         {
            prevNode = currentNode;
            currentNode = currentNode->next;
         }
      }
   }
}

void LinkedList::removeIndex(int index)
{
   if (index > this->size - 1)
   {
      std::cout << "Index out of bounds!" << std::endl;
   }
   else if (index == this->size - 1)
   {
      removeLast();
   }
   else if (index == 0)
   {
      removeHead();
   }
   else
   {
      Node* currentNode = head;
      Node* prevNode = head;
      int nodeIndex{ 0 };
      while (currentNode)
      {
         if (index == nodeIndex)
         {
            std::cout << "removing node with index: " << index << ", and value: " << currentNode->value << std::endl;
            prevNode->next = currentNode->next;
            delete currentNode;
            this->size--;
            break;
         }
         else
         {
            prevNode = currentNode;
            currentNode = currentNode->next;
            nodeIndex++;
         }
      }
   }
}

void LinkedList::set(int value, int index)
{
   if (!head)
   {
      std::cout << "List is empty" << std::endl;
   }
   else
   {
      Node* currentNode = head;
      if (index > size)
      {
         std::cout << "Index out of bounds!" << std::endl;
      }

      else if (index - 1 == 0)
      {
         currentNode->value = value;
         std::cout << "Changed Head value to: " << currentNode->value << std::endl;
      }

      else
      {
         currentNode = head->next;
         int nodeIndex = 1;
         while (currentNode)
         {
            if (nodeIndex == index - 1)
            {
               currentNode->value = value;
               std::cout << "Changed node value to: " << currentNode->value << std::endl;
               break;
            }
            else
            {
               nodeIndex++;
               currentNode = currentNode->next;
            }
         }
      }
   }
}

//void LinkedList::reverse()
//{
//   if (head)
//   {
//      Node* before = nullptr;
//      Node* temp = head;
//      Node* after = head->next;
//
//      //while (after)
//      //{
//      //   before = head;
//
//      //}
//
//   }
//}



