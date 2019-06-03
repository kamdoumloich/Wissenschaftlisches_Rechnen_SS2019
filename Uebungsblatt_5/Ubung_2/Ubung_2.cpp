#include<vector>
#include<iostream>
#include<cmath>
#include "NumVector.h"


int main(){
NumVector v(3);
v[0]=1; v[1]=3, v[2]=4;
const NumVector& w=v;
std::cout<<"norm is "<<w.norm()<<std::endl;
std::cout<<"vector is ["<<w[0]<<", "<<w[1]<<", "<<w[2]<<"]"<<std::endl;
}

// void vectorTest(std::vector<double>& v){}
// int main(){
// NumVector v(3);
// v.resize(2); // Darf wie andere std::vector Funktionen nicht sichtbar sein!
// vectorTest(v); // Hier muss auch ein Compiler Fehler auftreten!
// }
