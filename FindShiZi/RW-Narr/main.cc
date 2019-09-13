#include<iostream>
#include<vector>

using namespace std;

int maxarr (vector<int>&line , int size) {
  int max = line [0] , b = 0;
  for ( int i = 0; i<size; ++i  ) {
    if ( b >= 0  )
      b += line [i];
    else
      b = line [i];
    max = max >= b ? max : b;

  }
  return max;

}

int Max (vector<vector<int>> board , int num) {
  int sum = (int)0x80000000 , max;
  for ( int m = 0; m<num; ++m  ) {
    vector<int>line (num , 0);
    for ( int i = m; i<num; ++i  ) {
      int j = 0;
      for ( ; j<num; j++  ) {
        line [j] += board [i] [j];

      }
      max = maxarr (line , j);
      sum = max>sum ? max : sum;

    }

  }
  return sum;

}

int main () {
  int num , in;
  cin >> num;
  vector<vector<int>> board (num , vector<int> (num , 0));
  for ( int i = 0; i<num; ++i  ) {
    for ( int j = 0; j<num; ++j  ) {
      cin >> in;
      board [i] [j] = in;

    }

  }
  cout << Max (board , num) << endl;
  return 0;

}
