//
//  main.cpp
//  LL_class
//
//  Created by admin on 24.02.2021.
//

#include <iostream>
#include "Header.h"


using namespace std;

int main(int argc, const char * argv[]) {

    Node *head = new Node(10);
    cout << head->value << endl;
    cout << head->ptr << endl;

        
    LinkedList *list = new LinkedList(5);
    list->pushFront(10, list);
    list->pushFront(20, list);
    list->pushFront(30, list);
    list->pushBack(99, list);
    list->pushBack(89, list);
    list->pushBack(79, list);
    

    list->printLL(list);

    
    return 0;
}
