#include <iostream>

class LinkedList
{
public:
    LinkedList(int value)
    {
        if(head == nullptr)
        {
            head = new Node;
            head->value = value;
            head->next = nullptr;
            tail = head;
            std::cout << "Added Head Node: "<< 
                head->value << std::endl;
        }
    }
    
    struct Node
    {
        int value;
        Node* next;
    };
    
    //Adding an element to the end of the list
    void append(int value)
    {
        Node* currentNode = tail;
        if(currentNode->next == nullptr)
        {
            currentNode->next = new Node;
            currentNode->next->value = value;
            currentNode->next->next = nullptr;
            currentNode = currentNode->next;
            tail = currentNode;
            std::cout << "Added node to the end of the list: "<< currentNode->value << std::endl;
        }
    }
    
    // Add an element to the begining of the list
    void prepend(int value)
    {
        if(head != nullptr)
        {
            Node* previousHead = head;
            Node* newHead = new Node;
            newHead->value = value;
            newHead->next = previousHead;
            head = newHead;
        }
    }
    
    // inserts a node at a particular index
    void insert(int index, int value)
    {
        if (index == 0)
        {
            prepend(value);
        }
        else
        {
            Node* previousNode = head;
            Node* currentNode = head;
            int currentIndex = 0;
            bool found = false;
            while(currentNode != nullptr)
            {
                if(currentIndex == index)
                {
                    found = true;
                    Node* newNode = new Node;
                    newNode->value = value;
                    newNode->next = currentNode;
                    previousNode->next = newNode;
                    break;
                }
                else
                {
                    previousNode = currentNode;
                    currentNode = currentNode->next;
                    currentIndex++;
                }
            }
            if (!found)
            {
                std::cout << "Index Out of Bounds"<< std::endl;
            }
        }
    }
    
    //deletes the last element node in the list
    void deleteLast()
    {
        Node* currentNode = head;
        if (head == nullptr)
        {
            return;
        }
        else if (head->next == nullptr)
        {
            head = nullptr;
            std::cout << "Deleted head!" << std::endl;
        }
        else
        {
            while (currentNode)
            {
                if(currentNode->next == tail)
                {
                    tail = currentNode;
                    currentNode->next = nullptr;
                    std::cout << "Deleted last!" << std::endl;
                }
                else
                {
                    currentNode = currentNode->next;
                }
            }
        }
    }
    
    Node* get(int index)
    {
        Node* currentNode = head;
        int currentIndex = 0;
        while (currentNode)
        {
            if(currentIndex == index)
            {
                std::cout << "Found Node: "<< 
                    currentNode->value << std::endl;
                return currentNode;
            }
            else
            {
                currentIndex++;
                currentNode = currentNode->next;
            }
        }
        return currentNode;
    }
    
    bool set(int index, int value)
    {
        Node* currentNode = head;
        if (currentNode == nullptr)
        {
            std::cout << "List is Empty!" << std::endl;
            return false;
        }
        else
        {
            Node* currentNode = get(index);
            if (currentNode != nullptr)
            {
                std::cout << "Updated index: "<< index << ", with value: " << value << std::endl;
                currentNode->value = value;
                return true;
            }
            else
            {
                std::cout << "Index Out of Bounds"<< std::endl;
                return false;
            }
        }
    }
    
    // Print values of nodes in the list
    void printList()
    {
        Node* currentNode = head;
        if(currentNode != nullptr)
        {
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
};

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
