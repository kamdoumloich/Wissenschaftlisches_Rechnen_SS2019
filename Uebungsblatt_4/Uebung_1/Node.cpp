#include "Node.h"
#include "iostream"

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