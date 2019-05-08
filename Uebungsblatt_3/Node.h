#include <iostream>
#include <stdio.h>

#ifndef NODE_H_
#define NODE_H_

class Node
{
private:
    /* data */
    Node *next;

public:
    /* Konstruktoren */
    Node();
    Node(int);
    ~Node();

    /* data */
    friend class List;
    int value;

};

#endif /* NODE_H_ */