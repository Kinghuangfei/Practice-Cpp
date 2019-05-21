#include<iostream>
#include<vector>
using namespace std;

int main () {
  vector<int> arr;
  int m;
  while ( cin >> m  ) {
    arr.push_back (m);

  }
  int count = 1;
  int target = arr [0];
  for ( int i = 1; i<arr.size (); i++  ) {
    if ( arr [i] == target  ) {
      count++;

    }
    else {
      count--;
      if ( count == 0  ) {
        target = arr [i];
        count = 1;

      }

    }

  }
  cout << count << endl;
  system ("pause");
  return 0;

}

