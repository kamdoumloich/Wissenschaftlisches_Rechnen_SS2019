#include <iostream>
#include <stdio.h>

#include "List.h"
#include "Node.h"

using namespace std;

int main ();

int main ()
{
    // cout << "lol"<<'\n';
    List list;
    list.append(2);
    list.append(3);
    list.insert(list.first(), 1);
    for (Node *n = list.first(); n != 0; n = list.next(n))
        std::cout << n->value << std::endl;
    
    cout <<'\n'<<"Nach der Kopie"<<'\n';
    // Kopie von der Liste
    List list2 = list;
    for (Node *n = list2.first(); n != 0; n = list2.next(n))
        std::cout << n->value << std::endl;

    //Neue Elemente werden in der Liste hinzugefügt zur Prüfung der Methode testMinMax()
    cout <<'\n'<<"Prüfung der Methode testMinMax()"<<'\n';
    list.append(10);
    list.testListMinMax();

    return 0;
}