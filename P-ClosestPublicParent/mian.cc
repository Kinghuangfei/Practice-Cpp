#include <iostream>
using namespace std;

class LCA {
  public:
    int parent (int a) {
      int parent = a / 2;
      return parent>1 ? parent : 1;

    }
    int deep (int a) {
      int count = 0;
      while ( a != 1  ) {
        a = parent (a);
        count++;

      }
      return count;

    }
    int getLCA (int a , int b) {
      int min = 0; int max = 0;
      min = a>b ? b : a;
      max = a>b ? a : b;
      int max_parent = parent (max) , max_last = max;
      while ( max_parent >= min  ) {
        max_last = max_parent;
        max_parent = parent (max_parent);

      }
      if ( max_last == min  )
        return min;
      max = max_last;
      if ( deep (min) != deep (max)  )
        max = parent (max);
      while ( max != min  ) {
        max = parent (max);
        min = parent (min);

      }
      return min;

    }

};

int main () {
  LCA test;
  cout<<test.getLCA ( 12,13  );
  system ("pause");
  return 0;

}
