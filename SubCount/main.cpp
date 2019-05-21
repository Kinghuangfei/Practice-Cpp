#include<iostream>

using namespace std;

int main () {
  long n;
  while ( cin >> n  ) {
    long* arr = new long [n];
    long i = 0;
    while ( i != n  ) {
      cin >> arr [i++];

    }
    long up = 1 , down = 0 , start = -1 , tend_last = -1 , count = 0;
    for ( long i = 1; i<n; i++  ) {
      if ( arr [i]>arr [i - 1]  ) {
        if ( tend_last == down  ) {
          count++;
          tend_last = start;

        }
        else
          tend_last = up;

      }
      else if ( arr [i]<arr [i - 1]  ) {
        if ( tend_last == up  ) {
          count++;
          tend_last = start;

        }
        else
          tend_last = down;

      }
      else
        tend_last = start;

    }
    cout << count + 1 << endl;

  }
  return 0;

}
