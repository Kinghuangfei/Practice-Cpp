//左上到右下走法
#include<iostream>
#include<vector>
using namespace std;


int main () {
  int n = 0 , m = 0;
  while ( cin >> n >> m  ) {
    n++;
    m++;
    vector<vector<int>> arr;
    arr.resize (m);
    for ( size_t i = 0; i<arr.size (); i++  ) {
      arr [i].resize (n);
      for ( int j = 0; j<n; j++  ) {
        if ( j == 0 || i == 0  )
          arr [i] [j] = 1;
        else
          arr [i] [j] = 0;

      }

    }
    for ( int i = 1; i<m; i++  ) {
      for ( int j = 1; j<n; j++  ) {
        arr [i] [j] = arr [i] [j - 1] + arr [i - 1] [j];

      }

    }
    cout << arr [m - 1] [n - 1] << endl;

  }
  return 0;

}
