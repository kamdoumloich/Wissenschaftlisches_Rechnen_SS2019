#include <iostream>
#include <stdio.h>

#include "Node.h"

#ifndef LIST_H_
#define LIST_H_

class List
{
private:
    /* data */
    Node *first_;  //pointer to the first element
    Node *next_;  //pointer to the next element

public:
    /* Konstruktoren */
    List ();
    ~List();
    List (const List &);  //Copy-Konstruktor

    /* Methoden */
    Node* first() const;
    Node* next(const Node *n) const;
    void append (int i);
    void insert (Node *n, int i);
    void erase (Node *n);

    const Node* findMin() const;
    const Node* findMax() const;
    void testListMinMax();

};


#endif /* LIST_H_ */