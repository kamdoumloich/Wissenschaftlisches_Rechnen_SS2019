#include<vector>
#include<iostream>
#include<cmath>
#include "NumVector.h"

int main(){
  NumVector v(3);
  NumVector v2(2);
  v[0]=1; v[1]=3, v[2]=4;
  v2[0]=1; v2[1]=3, v2[2]=4;
  const NumVector& w=v;
  const NumVector& w2=v*v;
  const NumVector& w3=v*v2;
  std::cout<<"norm is "<<w.norm()<<std::endl;
  std::cout<<"vector is ["<<w[0]<<", "<<w[1]<<", "<<w[2]<<", "<<"]"<<std::endl;
  std::cout<<"vector is ["<<w2[0]<<", "<<w2[1]<<", "<<w2[2]<<", "<<"]"<<std::endl;
}
