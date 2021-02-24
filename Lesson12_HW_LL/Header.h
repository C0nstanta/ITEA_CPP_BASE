//
//  Header.h
//  LL_class
//
//  Created by admin on 24.02.2021.
//

#ifndef Header_h
#define Header_h

class Node
{
public:
    Node(int val, Node *p=nullptr);
    
    Node *ptr;
    int value;
};

class LinkedList
{

public:
    LinkedList(int init_nodes);
    ~LinkedList();
    
    
    void createLinkedList(int numNodes);
    void pushBack(int num, LinkedList *list);
    void pushFront(int num, LinkedList *list);
    void printLL(const LinkedList *list);

    Node* getHead(){return head;}
    Node* getTail(){return tail;}


    
private:
    Node *head;
    Node *tail;
    
};

#endif /* Header_h */
