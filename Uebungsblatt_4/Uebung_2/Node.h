#ifndef NODE_H
#define NODE_H

#include <memory>

class Node
{
public:
    int value;
    Node();
    Node(int);
    ~Node();
    shared_ptr<Node> next;
    friend class List;
};

#endif // NODE_H
