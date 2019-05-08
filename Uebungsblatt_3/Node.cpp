#include "Node.h"

using namespace std;

Node::Node()
{
    value = 0;
    next = nullptr;
}

Node::Node(int value_)
{
    value = value_;
    next = nullptr;
}

Node::~Node()
{
    value = 0;
    next = nullptr;
}