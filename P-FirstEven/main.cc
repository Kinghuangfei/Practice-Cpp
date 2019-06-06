#include<iostream>

using namespace std;

int main () {
  int n;
  while ( cin >> n  ) {
    int pos = 0 , flag = 0;
    if ( n<3  )
      pos = -1;
    else if ( n % 2  )
      pos = 2;
    else {
      pos = ((n - 4) % 4) == 0 ? 3 : 4;

    }
    cout << pos << endl;

  }
  return 0;

}
