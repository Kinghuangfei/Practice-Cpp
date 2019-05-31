#include<iostream>

using namespace std;

bool isSushu (int num) {
  for ( int i = 2; i <= num / 2; i++  ) {
    if ( !(num%i)  )
      return false;

  }
  return true;

}

int main () {
  int num;
  while ( cin >> num  ) {
    int min = num , min_left = 0 , min_right = 0;
    for ( int i = 2; i <= (num / 2 + 1); i++  ) {
      int left = i , right = num - i;
      if ( isSushu (left) && isSushu (right)  ) {
        int cha = right - left;
        if ( cha <= min  ) {
          min = cha;
          min_left = left;
          min_right = right;

        }

      }

    }
    if ( min_left<min_right  ) {
      cout << min_left << endl;
      cout << min_right << endl;

    }
    else {
      cout << min_right << endl;
      cout << min_left << endl;

    }

  }
  return 0;

}
