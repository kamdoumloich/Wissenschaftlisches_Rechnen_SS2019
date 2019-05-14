#ifndef LIST_H
#define LIST_H

#include "Node.h"
#include <memory>

class List
{
public:
    List();                          
    ~List();                         
    shared_ptr<Node> first() const;             
    shared_ptr<Node> next(const shared_ptr<Node> n) const; 
    void append(int i);              
    void insert(shared_ptr<Node> n, int i);     
    void erase(shared_ptr<Node> n);             

    // with the cache, the user have to call the following methods once. But if the Node
    // with the extremum is delete then he calls them once again
    const shared_ptr<Node> findMin() const; 
    const shared_ptr<Node> findMax() const; 
    void testListMinMax();

private:
    shared_ptr<Node> _first; // saves the first node of the list
    shared_ptr<Node> _last;  // save the current node, in order to avoid iterating throug the list all time
private:
    //cache
    mutable shared_ptr<Node> cachedMin; // saves the current minimum
    mutable shared_ptr<Node> cachedMax; // saves the current maximum
};

#endif // LIST_H