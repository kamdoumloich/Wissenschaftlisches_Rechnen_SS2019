#ifndef NODE_H
#define NODE_H

class Node
{
public:
    int value;
    Node();
    Node(int);
    ~Node();
    Node *next;
    friend class List;
};

#endif // NODE_H