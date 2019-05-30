#include<iostream>

using namespace std;

int main () {
  size_t a = 0;
  while ( cin >> a  ) {
    size_t i = 1 , n = 0 , count = 0 , max = 0;
    while ( n != 31  ) {
      if ( a&(i << n)  )
        count++;
      else {
        max = max>count ? max : count;
        count = 0;

      }
      n++;

    }
    cout << max << endl;

  }
  return 0;

}
