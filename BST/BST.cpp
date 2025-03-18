/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

struct Node
{
   Node* left;
   Node* right;
   int value;
   
   Node(int value)
   {
      this->value = value;
      this->left = nullptr;
      this->right = nullptr;
   }
};

class BST
{
public:
   BST(int value)
   {
      parent = new Node(value);
      std::cout << "Added parent" <<  std::endl;
   }
   
   Node* getRoot()
   {
      return parent;
   }
   
   void insert(int value)
   {
      Node* currentNode = parent;
      if (parent) // tree is not empty
      {
         while (currentNode)
         {
            if (value > currentNode->value)
            {
               if (currentNode->right) // current node has a child
               {
                  currentNode = currentNode->right;
                  continue;
               }
               else //we reached the leaf!
               {
                  std::cout << "Added right child" <<  std::endl;
                  Node* newNode = new Node(value);
                  currentNode->right = newNode;
                  break;
               }
            }
            else
            {
               if (currentNode->left) // current node has a child
               {
                  currentNode = currentNode->left;
                  continue;
               }
               else //we reached the leaf!
               {
                  std::cout << "Added left child" <<  std::endl;
                  Node* newNode = new Node(value);
                  currentNode->left = newNode;
                  break;
               }
            }
         }
      }
      else // all nodes got deleted, add parent
      {
         Node* newNode = new Node(value);
         parent = newNode;
      }
   }
   
   void printTree(Node* node, int level = 0) 
   {
      if (node != nullptr) 
      {
         // Print right subtree first so it appears at the top
         printTree(node->right, level + 1);

         // Indentation for the current level
         for (int i = 0; i < level; i++) 
         {
            std::cout << "    ";
         }
         std::cout << node->value << std::endl;

         // Print left subtree
         printTree(node->left, level + 1);
      }
   }
   
   bool contains(int value)
   {
      if (parent)
      {
         Node* currentNode = parent;
         bool found{false};
         while (currentNode && !found)
         {
            if (value == currentNode->value)
            {
               found = true;
               std::cout << "Tree contains value: " << value << std::endl;
               return found;
            }
            else if (value > currentNode->value)
            {
               currentNode = currentNode->right;
            }
            else if (value < currentNode->value)
            {
               currentNode = currentNode->left;
            }
         }
         std::cout << "Tree does not contain value: "<< value << std::endl;
         return found;
      }
   }
private:
   Node* parent = nullptr;
};

int main()
{
   
   BST myBst(10);
   myBst.insert(15);
   myBst.insert(8);
   myBst.insert(13);
   myBst.insert(16);
   myBst.insert(9);
   myBst.insert(7);
   myBst.printTree(myBst.getRoot());
   myBst.contains(-9);
   return 0;
}
