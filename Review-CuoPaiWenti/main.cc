#include<iostream>
#include<vector>

using namespace std;

int f (int i) {
    if ( i <= 1  )
          return 0;
      if ( i == 2  )
            return 1;
        return (i-1)*f(i-1)+f(i-2);

}

int main () {
    int num;
    while ( cin >> num  ) {
          int ways = num*f(num-1);
              cout << ways << endl;
                
    }
      return 0;

}
