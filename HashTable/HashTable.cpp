/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>

using std::string;

struct Node
{
        string key;
        int value;
        Node* next;

        Node(string key, int value) : key(key), value(value), next(nullptr) {}
};

class HashTable
{
private:
        static const int SIZE = 7;
        Node* nodeArray[SIZE] = {nullptr};
public:
        void printTable()
        {
                for (int i = 0; i < SIZE; i++)
                {
                        if (nodeArray[i])
                        {
                           std::cout << i << ": ";
                                std::cout << nodeArray[i]->key << ": ";
                                std::cout << nodeArray[i]->value;
                                if (nodeArray[i]->next)
                 {
              Node* currentNode = nodeArray[i]->next;
              while (currentNode)
              {
                 std::cout << " | ";
                 std::cout << currentNode->key << ": ";
                                      std::cout << currentNode->value;
                 currentNode = currentNode->next;
              }
                 }
                 std::cout << std::endl;
                        }
                        else
                        {
                                std::cout << i << ": Empty" << std::endl;
                        }
                }
        }
        
        int hashFx(string key)
        {
           int asciiValue = 0;
           for (int i = 0; i < key.size(); i++)
           {
              asciiValue += int(key[i]);
           }
           asciiValue = (asciiValue % 6) + 1;
           std::cout << "Returning index: "<< asciiValue << std::endl;
           return asciiValue;
        }
        
        void set(string key, int value)
        {
           int index = hashFx(key);
      Node* newNode = new Node(key, value);
           if (nodeArray[index])
           {
              Node* currentNode = nodeArray[index];
              Node* lastNode = nodeArray[index];
              while (currentNode)
              {
                 lastNode = currentNode;
                 currentNode = currentNode->next;
                 
              }
              lastNode->next = newNode;
           }
           else
           {
              nodeArray[index] = newNode;
           }
        }
        
        void get(string key)
        {
      int index = hashFx(key);
      bool found{false};
      if (!nodeArray[index])
      {
         std::cout << "Key does not exist!" << std::endl;
      }
      else if (nodeArray[index])
      {
         Node* currentNode = nodeArray[index];
         int counter = 1;
         while (currentNode != nullptr && !found)
         {
            std::cout << "Here!"<< std::endl;
            if (currentNode->key != key)
            {
               std::cout << "Here2!"<< std::endl;
               counter++;
               currentNode = currentNode->next;
            }
            else
            {
               std::cout << "Found key at index: "<< index << ", block: "<< counter << std::endl;
               found = true;
            }
         }
         if (!found)
            std::cout << "Key does not exist!" << std::endl;
      }
        }
};

int main()
{
        HashTable myHashTable;
        myHashTable.printTable();
        myHashTable.set("Kiro", 1);
        myHashTable.printTable();
        myHashTable.set("Dodo", 1);
        myHashTable.printTable();
        myHashTable.set("Mrmr", 2);
        myHashTable.printTable();
        myHashTable.set("Sasa", 3);
        myHashTable.printTable();
        myHashTable.set("Mama", 4);
        myHashTable.printTable();
        myHashTable.set("Jeje", 5);
        myHashTable.printTable();
        myHashTable.get("Mrmr");
        return 0;
}
