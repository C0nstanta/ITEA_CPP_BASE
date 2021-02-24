//
//  LinkedList.cpp
//  LL_class
//
//  Created by admin on 24.02.2021.
//

#include <iostream>
#include <stdio.h>
#include "Header.h"

using namespace std;

Node::Node(int val, Node *p)
{
    value = val;
    Node *ptr = p;

}

LinkedList::LinkedList(int initNodes)
{
    head = new Node(rand() % 100);
    tail = head;
    
    Node *tPtr = head;
//    Node *tPtrTail = tail;
    
    for (int i = 0; i < initNodes; i++)
    {
        if (!tPtr->ptr)
        {
            Node *newNode = new Node(rand() % 100);
            tPtr->ptr = newNode;
            tPtr = newNode;
            tail = newNode;
        }
    }
    
}

void LinkedList::printLL(const LinkedList *list)
{
    if (!list->head->ptr)
    {
        cout << "Your Linked List is empty!" << endl;
        return;
    }
    
    Node *tPtr = list->head;
    
    int i = 0;
    while (tPtr->ptr)
    {
        cout << "Pointer# " << i << ": " << "val = " << tPtr->value <<
            " , nextNode addr: " << tPtr->ptr <<endl;
        tPtr = tPtr->ptr;
        i++;
    }
}

void LinkedList::pushFront(int num, LinkedList* list)
{
    if (!list->getHead()->ptr)
    {
        cout << "Your head node is empty!" << endl;
        return;
    }
    
    Node *newNode = new Node(num);
    newNode->ptr = list->getHead();
    head = newNode;
    
}

void LinkedList::pushBack(int num, LinkedList* list)
{
    if (list->getTail()->ptr)
    {
        cout << "Your tail node is NOT empty!" << endl;
        return;
    }
    
    Node *newNode = new Node(num);
    list->tail->ptr = newNode;
    tail = newNode;

}

LinkedList::~LinkedList()
{
    if (head->ptr)
    {
        Node *tPtr = head;
        while (tPtr)
        {
            tPtr = head->ptr;
            delete head;
            head = tPtr;
        }
        
    }
    else
    {
        cout << "Your Linked List is empty!" << endl;
    }
}
