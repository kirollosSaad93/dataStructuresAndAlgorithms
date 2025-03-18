/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

struct Node
{
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

class LinkedList
{
public:
   LinkedList(int value)
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
         tail = newNode;
         length++;
         std::cout << "New Tail is: "<< tail->value << std::endl;
         std::cout << "Prev Tail is: "<< tempNode->value << std::endl;
      }
   }
   
   void prepend(int value)
   {
      if (head)
      {
         Node* tempNode = head;
         Node* newHead = new Node(value);
         head = newHead;
         head->next = tempNode;
         length++;
         std::cout << "New Head is: "<< head->value << std::endl;
         std::cout << "Prev Head is: "<< tempNode->value << std::endl;
      }
   }
   
   void deleteFirst()
   {
      if (head)
      {
         if (head->next)
         {
            Node* newHead = head->next;
            delete head;
            head = newHead;
            length--;
         }
         else
         {
            delete head;
            std::cout << "List is empty!" << std::endl;
         }
      }
      
   }
   
   void printList()
   {
      if(head)
      {
         Node* currentNode = head;
         std::cout << "My List:["; 
         while(currentNode != nullptr)
         {
            std::cout << currentNode->value;
            if (currentNode->next != nullptr)
            {
               std::cout << ", ";
            }
            currentNode = currentNode->next;
         }
         std::cout << "]" << std::endl;
      }
      else
      {
         std::cout << "List is Empty!"<< std::endl;
      }
   }
   
private:
   Node* head = nullptr;
   Node* tail = nullptr;
   int length{0};
};

class Stack
{
public:
  Stack(int value)
  {
     myDll = new LinkedList(value);
     myDll->printList();
  }
  
  void push(int value)
  {
     myDll->prepend(value);
     myDll->printList();
  }
  
   void pop()
   {
      myDll->deleteFirst();
      myDll->printList();
   }
  
private:
   LinkedList* myDll = nullptr;
};

class Queue
{
public: 
   Queue(int value)
   {
     myDll = new LinkedList(value);
     myDll->printList();
   }
   
   void enque(int value)
   {
     myDll->append(value);
     myDll->printList();
   }
   
   void deque()
   {
     myDll->deleteFirst();
     myDll->printList();
   }
    
private:
   LinkedList* myDll = nullptr;
};

int main()
{ 
   Stack myStack(5);
   myStack.push(4);
   myStack.push(3);
   myStack.push(2);
   myStack.push(1);
   myStack.push(0);
   myStack.pop();
   myStack.pop();
   myStack.pop();
   myStack.pop();
   myStack.pop();
   myStack.pop();
   
   Queue myQueue(5);
   myQueue.enque(6);
   myQueue.enque(7);
   myQueue.enque(8);
   myQueue.enque(9);
   myQueue.enque(10);
   myQueue.deque();
   myQueue.deque();
   myQueue.deque();
   myQueue.deque();
   myQueue.deque();
   myQueue.deque();
   return 0;
}
