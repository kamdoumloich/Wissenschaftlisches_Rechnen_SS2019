#include "List.h"
#include "iostream"
#include <memory>

List::List() 
{
    this->_first = 0;
    this->_last = 0;
    this->cachedMax = 0;
    this->cachedMin = 0;
}

List::~List() 
{
    while (_first) 
    {
        shared_ptr<Node> tmp = _first->next;
        delete _first;
        this->_first = tmp;
    }
    //    delete _last; // no use because of the code above, might throw a segmentation fault error, right?
    delete cachedMax;
    delete cachedMin;
    this->_first = 0;
    this->_last = 0;
    this->cachedMax = 0;
    this->cachedMin = 0;
}

shared_ptr<Node> List::first() const 
{
    return this->_first;
}

shared_ptr<Node> List::next(const shared_ptr<Node> n) const 
{
    return n->next;
}

void List::append(int i) 
{
    shared_ptr<Node> n = new Node(i);
    if (!this->_first) // first insert into the list
    {
        this->_first = n;
        this->_last = n;
    }
    else if (this->_first && !this->_first->next) // second insert into the list
    {
        this->_last = n;
        this->_first->next = this->_last;
    }
    else // other inserts into the list
    {
        this->_last->next = n;
        this->_last = n;
    }

    // refresh the cache
    if (this->cachedMax && this->cachedMax->value < n->value)
    {
        this->cachedMax = n;
    }
    if (this->cachedMin && this->cachedMin->value > n->value)
    {
        this->cachedMin = n;
    }
}

void List::insert(shared_ptr<Node> n, int i) 
{
    shared_ptr<Node> current = new Node(i);
    if (n == this->_first) 
    {
        current->next = this->_first;
        this->_first = current;
        return;
    }
    else
    {
        shared_ptr<Node> tmp = this->_first;
        shared_ptr<Node> previous = new Node();
        while (tmp != n)
        {
            previous = tmp;
            tmp = tmp->next;
        }
        previous->next = current;
        current->next = tmp;
    }

    // refresh the cache
    if (this->cachedMax && this->cachedMax->value < current->value)
    {
        this->cachedMax = current;
    }
    if (this->cachedMin && this->cachedMin->value > current->value)
    {
        this->cachedMin = current;
    }
}

void List::erase(shared_ptr<Node> n) // remove n from the list
{
    // reset the cache according to the following conditions
    if (this->cachedMin && n->value <= this->cachedMin->value)
    {
        this->cachedMin = 0;
    }
    if (this->cachedMax && n->value >= this->cachedMax->value)
    {
        this->cachedMax = 0;
    }

    if (n == this->_last) // last element
    {
        delete _last;
        this->_last = 0;
        return;
    }

    if (n == this->_first) // first element
    {
        this->_first = this->_first->next;
        delete n;
        n = 0;
        return;
    }

    // elements inbetween
    shared_ptr<Node> tmp = this->_first;
    shared_ptr<Node> previous = new Node();
    while (tmp != n)
    {
        previous = tmp;
        tmp = tmp->next;
    }
    previous->next = tmp->next;
    delete tmp;
    tmp = 0;
}

const shared_ptr<Node> List::findMin() const
{
    if (this->cachedMin)
    {
        return this->cachedMin;
    }
    int min = this->_first->value;
    shared_ptr<Node> node = this->_first;
    shared_ptr<Node> it = this->_first;
    while (it)
    {
        int tmp = it->value;
        if (tmp < min)
        {
            min = tmp;
            node = it;
        }
        it = it->next;
    }
    this->cachedMin = node; // one search an then cached
    return this->cachedMin;
}

const shared_ptr<Node> List::findMax() const
{
    if (this->cachedMax)
    {
        return this->cachedMax;
    }
    int max = this->_first->value;
    shared_ptr<Node> node = this->_first;
    shared_ptr<Node> it = this->_first;
    while (it)
    {
        int tmp = it->value;
        if (tmp > max)
        {
            max = tmp;
            node = it;
        }
        it = it->next;
    }
    this->cachedMax = node; // one search and then cached
    return this->cachedMax;
}

void List::testListMinMax()
{
    std::cout << '\n'
         << "Der min in der Liste ist: " << this->findMin()->value;
    std::cout << '\n'
              << "Der max in der Liste ist: " << this->findMax()->value;
    std::cout << std::endl;
}