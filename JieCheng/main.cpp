#include<iostream>

using namespace std;

template <size_t N>
struct Sum{
  enum{Ret = N+Sum<N-1>::Ret};
};

template <>
struct Sum<1>{//limit
 enum {Ret = 1};
};

int main(){
  cout<< Sum<100>::Ret<<endl;
  return 0;
}
