#ifndef LIST_H
#define LIST_H

#include "Node.h"

class List
{
public:
    List();                          
    ~List();                         
    Node *first() const;             
    Node *next(const Node *n) const; 
    void append(int i);              
    void insert(Node *n, int i);     
    void erase(Node *n);             

    const Node *findMin() const; 
    const Node *findMax() const; 
    void testListMinMax();

private:
    Node *_first; // saves the first node of the list
    Node *_last;  // save the current node, in order to avoid iterating throug the list all time

    //cache
    mutable Node *cachedMin; // saves the current minimum
    mutable Node *cachedMax; // saves the current maximum
};

#endif // LIST_H