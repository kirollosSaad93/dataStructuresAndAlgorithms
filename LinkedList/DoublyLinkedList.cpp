#include <iostream>

class Node
{
public:  
   int value;
   Node* next;
   Node* prev;

   Node(int value)
   {
      this->value = value;
      this->next = nullptr;
      this->prev = nullptr;
   }
};

class DLL //Doubly Linked List
{
public:
   DLL(int value): length(0), head(nullptr), tail(nullptr)
   {
      head = new Node(value);
      tail = head;
      length++;
   }

   void append(int value)
   {
      if (tail)
      {
         Node* newNode = new Node(value);
         Node* tempNode = tail;
         tempNode->next = newNode;
         newNode->prev = tempNode;
         tail = newNode;
         length++;
         std::cout << "Tail is now: " << tail->value << std::endl;
      }
      else
      {
         std::cout << "List is empty!" << std::endl;
      }
   }

   // Print values of nodes in the list
   void printList()
   {
      if(head)
      {
         Node* currentNode = head;
         std::cout << "My List:["; 
         while(currentNode != nullptr)
         {
            if (currentNode->prev)
            {
               std::cout << currentNode->prev->value << " <- ";
            }
            else
            {
               std::cout << "nullptr <- ";
            }
            
            std::cout << "(" << currentNode->value << ")";
            
            if (currentNode->next != nullptr)
            {
               std::cout << " -> " << currentNode->next->value;
               std::cout << " | ";
            }
            else 
            {
               std::cout << " -> nullptr";
            }
            currentNode = currentNode->next;
         }
         std::cout << "]" << std::endl;
         std::cout << "List length is: " << length << std::endl;
      }
      else
      {
         std::cout << "List is Empty!"<< std::endl;
      }
   }

   void deleteLast()
   {
      if (tail->value != head->value)
      {
         Node* tempNode = tail;
         tail = tail->prev;
         tail->next = nullptr;
         length--;
         std::cout << "Deleted Node: "<< tempNode->value << std::endl;
         delete tempNode;
      }
      else if (tail->value == head->value)
      {
         head = nullptr;
         tail = nullptr;
         delete head;
         length--;
         std::cout << "Deleted Head!"<< std::endl;
      }
      else
      {
         std::cout << "List is empty!" << std::endl;
      }
   }

   void prepend(int value)
   {
      if (head)
      {
         Node* newHeadNode = new Node(value);
         Node* tempNode = head;
         tempNode->prev = newHeadNode;
         newHeadNode->next = tempNode;;
         head = newHeadNode;
         length++;
         std::cout << "New head is: "<< head->value << std::endl;
      }
      else
      {
         std::cout << "List is empty!" << std::endl;
      }
   }
   void deleteFirst()
   {
      if (head)
      {
         Node* tempNode = head;
         head = head->next;
         head->prev = nullptr;
         std::cout << "Deleted head: " << tempNode->value;
         std::cout << ", new head is: " << head->value << std::endl;
         delete tempNode;
         length--;
      }
      else
      {
         std::cout << "List is empty!" << std::endl;
      }
   }
   
   void insert(int index, int value)
   {
      bool found{false};
      int counter = 1;
      if (head)
      {
         if (counter == index) // insert at head
         {
            prepend(value);
         }
         else if (index == length) //insert at last node
         {
            append(value);
         }
         else //otherwise find the index in interest
         {
            Node* currentNode = head->next;
            while (!found && currentNode)
            {
               counter++;
               if (index == counter)
               {
                  std::cout << "found index at node: "<< currentNode->value << std::endl;
                  Node* prevNode = currentNode->prev;
                  Node* newNode = new Node(value);
                  newNode->next = currentNode;
                  newNode->prev = prevNode;
                  prevNode->next = newNode;
                  currentNode->prev = newNode;
                  found = true;
                  length++;
               }
               currentNode = currentNode->next;
               }
               if (!found)
               {
                  std::cout << "Index not found!" << std::endl;
               }
         }
      }
   }
   
   //get node by index
   Node* getByIndex(int index)
   {
      int counter = 1;
      bool found{false};
      if (index == 1)
      {
         std::cout << "Returning head"<< std::endl;
         return head;
      }
      else if (index == length)
      {
         std::cout << "Returning tail"<< std::endl;
         return tail;
      }
      else if (index < 1 || index > length)
      {
         return nullptr;
         std::cout << "Index out of bounds!" << std::endl;
      }
      else if (head)
      {
         Node* currentNode = head;
         while (currentNode && !found)
         {
            if (counter == index)
            {
               found = true;
               std::cout << "Returning node: "<< currentNode->value << std::endl;
               return currentNode;
            }
            counter++;
            currentNode = currentNode->next;
         }
      }
      else
      {
         return nullptr;
         std::cout << "List is empty!" << std::endl;
      }
   }
   
   Node* getByValue(int value)
   {
      bool found{false};
      int counter = 1;
      if (head)
      {
         Node* currentNode = head;
         while(currentNode && !found)
         {
            if (value == currentNode->value)
            {
               found == true;
               std::cout << "Returning node: "<< currentNode->value << std::endl;
               return currentNode;
            }
            currentNode = currentNode->next;
         }
         if (!found)
         {
            return nullptr;
            std::cout << "Node with value: "<< value << ", does not exist!" << std::endl;
         }
      }
      else
      {
         return nullptr;
         std::cout << "List is empty!" << std::endl;
      }
   }
   
   void set(int index, int value)
   {
      Node* currentNode = getByIndex(index);
      if (currentNode)
      {
         currentNode->value = value;
      }
   }

   void swapFirstLast()
   {
      if (head != nullptr && length >= 2)
      {
         Node* newHead = tail;
         Node* newTail = head;
            
         //update the tail node to be the new head to point to 2nd node
         newHead->next = head->next;
            
         //update the 2nd node to point to new head(previously tail)
         Node* secondNode = head->next;
         secondNode->prev = newHead;
            
         //update the head node to be the new tail and point the second to last node
         newTail->prev = tail->prev;
            
         //update the second to last node to point to the new tail (previously head)
         Node* secondToLastNode = tail->prev;
         secondToLastNode->next = newTail;
            
         //null the prev to head and next to tail
         newHead->prev = nullptr;
         newTail->next = nullptr;

         //finally update head and tail to the newly created nodes
         head = newHead;
         tail = newTail;
      }
   }
private:
Node* head;
Node* tail;
int length;
};

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
