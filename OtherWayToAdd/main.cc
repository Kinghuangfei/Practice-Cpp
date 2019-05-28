#include<iostream>
using namespace std;

class UnusualAdd {
  public:
    int addAB (int A , int B) {
      int up_bit , add_bit;
      do {
        up_bit = (A&B) << 1;
        add_bit = A^B;
        A = up_bit;
        B = add_bit;

      } while ( up_bit  );
      return add_bit;

    }

};


int main(){
  UnusualAdd test;
  int A,B;
  cin>>A>>B;
  int count=test.addAB(A,B);
  cout<<count<<endl;
  return 0;
}
