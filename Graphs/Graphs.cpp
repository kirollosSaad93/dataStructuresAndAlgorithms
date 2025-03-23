#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>

using std::string, std::unordered_map, std::unordered_set;

class Graph
{
private:
   unordered_map<string, unordered_set<string>> adjList;
   
public:
   bool addVertex(string value)
   {
      if (adjList.count(value) == 0)
      {
         adjList[value];
         std::cout << "Added Key: " << value << std::endl;
         return true;
      }
      return false;
   }
   
   bool addEdge(string value1, string value2)
   {
      if (!adjList.count(value1) == 0 && !adjList.count(value2) == 0)
      {
         adjList.at(value1).insert(value2);
         adjList.at(value2).insert(value1);
         std::cout << value1 << "<-->"<< value2 << std::endl;
         return true;
      }
      else
      {
         if (adjList.count(value1) == 0 && adjList.count(value2) == 0)
         {
            std::cout << "You need to add both verticies first" << std::endl;
         }
         else if (adjList.count(value1) == 0)
         {
            std::cout << "You need to add vertex first for value: " << value1 << std::endl;
         }
         else
         {
            std::cout << "You need to add vertex first for value: " << value1 << std::endl;
         }
      }
      return false;
   }
   
   bool removeEdge(string value1, string value2)
   {
      if (adjList.count(value1) != 0 && adjList.count(value2) != 0)
      {
         adjList.at(value1).erase(value2);
         adjList.at(value2).erase(value1);
         std::cout << "Removed edge" << std::endl;
         return true;
      }
      return false;
   }
   
   void removeVertex(string value)
   {
      if (adjList.count(value) != 0)
      {
         adjList.erase(value);
      }
      for (auto it = adjList.begin(); it != adjList.end(); it++)
      {
         if (it->second.count(value) != 0) 
         {
            std::cout << "Removed Edge: "<< value << ", from Vertex: " << it->first << std::endl;
            it->second.erase(value);
         }
      }
   }
   
   void printGraph()
   {
      int counter = 1;
      if (adjList.begin() == adjList.end())
         return;
         
      for (auto it = adjList.begin(); it != adjList.end(); it++)
      {
         std::cout << counter << ": "<< it->first << std::endl;
         counter ++;
      }
   }
};
int main()
{
   Graph* myGraph = new Graph();
   myGraph->addVertex("Kiro");
   myGraph->addVertex("Dodo");
   myGraph->addEdge("Kiro","Dodo");
   myGraph->printGraph();
   myGraph->removeEdge("Kiro","Dodo");
   myGraph->removeVertex("Dodo");
   myGraph->printGraph();

   return 0;
}