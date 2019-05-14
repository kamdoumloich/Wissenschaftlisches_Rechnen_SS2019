// #ifndef NODE_2
// #define NODE_2
// #include <memory>

// using namespace std;

// class Node
// {
// public:
//     Node():value(0), next(0){}
//     Node(int value):value(value), next(0) {}
//     int value;
// //    Node *next;
//     shared_ptr<Node> next;
// };


// #endif // NODE_2



// #ifndef LIST_2_H
// #define LIST_2_H

// #include "node_2.h"
// #include <memory>

// using namespace std;

// class List
// {
// public:
//     List(); // create and empty list
//     ~List(); // clean up the list and all nodes
//     shared_ptr<Node> first() const; // return a pointer to the first entry
//     shared_ptr<Node> next(const shared_ptr<Node> n) const; // return a pointer to the node after n
//     void append(int i); // append a value to the end of the list
//     void insert(shared_ptr<Node> n, int i); // insert a value before n
//     void erase(shared_ptr<Node> n); // remove n from the list

//     // with the cache, the user have to call the following methods once. But if the Node
//     // with the extremum is delete then he calls them once again
//     const shared_ptr<Node> findMin() const; // return the Node pointer with the min value
//     const shared_ptr<Node> findMax() const; // return the Node pointer with the max value




// private:
//     shared_ptr<Node> _first; // saves the first node of the list
//     shared_ptr<Node> _last;  // save the current node, in order to avoid iterating throug the list all time
// private:
//     //cache
//     mutable shared_ptr<Node> cachedMin; // saves the current minimum
//     mutable shared_ptr<Node> cachedMax; // saves the current maximum

// };

// #endif // LIST_2_H


// #include "list_2.h"

// using namespace std;

// List::List() // create and empty list
// {
//     this->_first = 0;
//     this->_last = 0;
//     this->cachedMax = 0;
//     this->cachedMin = 0;
// }

// List::~List() // clean up the list and all nodes
// {
//     while(_first) // delete all the content of the list, starting at the first element
//     {
//         shared_ptr<Node> tmp = _first->next;
//         _first.reset();
//         this->_first = tmp;
//     }
// //    delete _last; // no use because of the code above, might throw a segmentation fault error, right?
//     cachedMax.reset();
//     cachedMin.reset();
//     // because of reset() we get an empty pointer. But... ↓
//     this->_first = 0;
//     this->_last = 0;
//     this->cachedMax = 0;
//     this->cachedMin = 0;
// }

// shared_ptr<Node> List::first() const // return a pointer to the first entry
// {
//     return this->_first;
// }

// shared_ptr<Node> List::next(const shared_ptr<Node> n) const // return a pointer to the node after n
// {
//     return n->next;
// }

// void List::append(int i) // append a value to the end of the list
// {
//     shared_ptr<Node> n(new Node(i));
//     if(!this->_first) // first insert into the list
//     {
//         this->_first = n;
//         this->_last = n;
//     } else if (this->_first && !this->_first->next) // second insert into the list
//     {
//         this->_last= n;
//         this->_first->next = this->_last;
//     } else // other inserts into the list
//     {
//         this->_last->next = n;
//         this->_last = n;
//     }

//     // refresh the cache
//     if(this->cachedMax && this->cachedMax->value < n->value)
//     {
//         this->cachedMax = n;
//     }
//     if(this->cachedMin && this->cachedMin->value > n->value)
//     {
//         this->cachedMin = n;
//     }
// }

// void List::insert(shared_ptr<Node> n, int i) // insert a value before n
// {
//     shared_ptr<Node> current(new Node(i));
//     if(n == this->_first) // insert before the first element
//     {
//         current->next = this->_first;
//         this->_first = current;
//         return;
//     } else
//     {
//         shared_ptr<Node> tmp = this->_first;
//         shared_ptr<Node> previous(new Node());
//         while(tmp != n)
//         {
//             previous = tmp;
//             tmp = tmp->next;
//         }
//         previous->next = current;
//         current->next = tmp;
//     }

//     // refresh the cache
//     if(this->cachedMax && this->cachedMax->value < current->value)
//     {
//         this->cachedMax = current;
//     }
//     if(this->cachedMin && this->cachedMin->value > current->value)
//     {
//         this->cachedMin = current;
//     }

// }

// void List::erase(shared_ptr<Node> n) // remove n from the list
// {
//     // reset the cache according to the following conditions
//     if(this->cachedMin && n->value <= this->cachedMin->value)
//     {
//         this->cachedMin.reset();
//     }
//     if(this->cachedMax && n->value >= this->cachedMax->value)
//     {
//         this->cachedMax.reset();
//     }

//     if(n == this->_last) // last element
//     {
//         _last.reset();
//         this->_last = 0;
//         return;
//     }

//     if( n == this->_first) // first element
//     {
//         this->_first = this->_first->next;
//         n.reset();
//         n = 0;
//         return;
//     }

//     // elements inbetween
//     shared_ptr<Node> tmp = this->_first;
//     shared_ptr<Node> previous(new Node());
//     while(tmp != n)
//     {
//         previous = tmp;
//         tmp = tmp->next;
//     }
//     previous->next = tmp->next;
//     tmp.reset();
//     tmp = 0;
// }

// const shared_ptr<Node> List::findMin() const
// {
//     if(this->cachedMin)
//     {
//         return this->cachedMin;
//     }
//     int min = this->_first->value;
//     shared_ptr<Node> node = this->_first;
//     shared_ptr<Node> it = this->_first;
//     while(it)
//     {
//         int tmp = it->value;
//         if(tmp < min)
//         {
//             min = tmp;
//             node = it;
//         }
//         it = it->next;
//     }
//     this->cachedMin = node; // one search an then cached
//     return this->cachedMin;
// }

// const shared_ptr<Node> List::findMax() const
// {
//     if(this->cachedMax)
//     {
//         return this->cachedMax;
//     }
//     int max = this->_first->value;
//     shared_ptr<Node> node = this->_first;
//     shared_ptr<Node> it = this->_first;
//     while(it)
//     {
//         int tmp = it->value;
//         if(tmp > max)
//         {
//             max = tmp;
//             node = it;
//         }
//         it = it->next;
//     }
//     this->cachedMax = node; // one search and then cached
//     return this->cachedMax;
// }
