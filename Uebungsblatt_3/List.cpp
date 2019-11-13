#include "List.h"

using namespace std;

List::List()
{
    first_ = new Node();
    next_ = new Node();
}

List::List(const List &list_)
{
    first_ = list_.first_;
    next_ = list_.next_;
}

List::~List() 
{
    Node *node_tmp = first_;
    Node *next_node = new Node();

    if (node_tmp != nullptr)
    {
        while(next(node_tmp) != nullptr)
        {
            next_node = next(node_tmp);
            delete node_tmp;
            node_tmp = next_node;
        }
        delete node_tmp;
        delete next_node;
    }
}

Node* List::first() const 
{
    return first_;
}

Node* List::next(const Node *n) const
{
    return n->next;
}

void List::append (int i)
{
    Node *node_tmp = first_;
    Node *next_node = new Node();

    if (node_tmp->value != 0)
    {
        while(node_tmp->next != nullptr)
        {
            next_node = next(node_tmp);
            node_tmp = next_node;
        }
        node_tmp->next = new Node(i);
    }
    else
    {
        first_ = new Node(i);
    }
}

void List::insert (Node *n, int i)
{
    Node *current_node = first_;
    Node *next_node = first_;
    Node *prev_node = first_;
    Node *tmp;

    // Kann mehr einfacher gemacht werden
    if (current_node != n)
    {
        while(current_node != n)
        {
            prev_node = current_node;
            next_node = next(current_node);
            current_node = next_node;
        }
        tmp = new Node(i);
        tmp->next = current_node;
        prev_node = tmp;
    }
    else
    { 
        tmp = new Node(i);
        tmp->next = current_node;
        first_ = tmp;
    }
}

void List::erase (Node *n)
{
    Node *node_tmp = first_;
    Node *next_node = nullptr;

    if (node_tmp != n)
    {
        while(node_tmp != n)
        {
            next_node = next(node_tmp);
            node_tmp = next_node;
        }
        next_node = next(node_tmp);
        node_tmp->next = next(next(node_tmp));
        delete next_node;
    }
    else
    {
        node_tmp->next = nullptr;
    }
}

const Node* List::findMin() const
{
    Node *node_tmp = first_;
    Node *min_node = first_;
    Node *next_node = new Node();

    while(node_tmp->next != nullptr)
    {
        next_node = next(node_tmp);
        node_tmp = next_node;
        if(node_tmp->value < min_node->value)
            min_node = node_tmp;
    }
    return min_node;
}

const Node* List::findMax() const
{
    Node *node_tmp = first_;
    Node *max_node = first_;
    Node *next_node = new Node();

    while(node_tmp->next != nullptr)
    {
        next_node = next(node_tmp);
        node_tmp = next_node;
        if(node_tmp->value > max_node->value)
            max_node = node_tmp;
    }
    return max_node;
}

void List::testListMinMax()
{
    cout <<'\n'<<"Der min in der Liste ist: "<< this->findMin()->value;
    cout <<'\n'<<"Der max in der Liste ist: "<< this->findMax()->value;
    cout <<endl;
}