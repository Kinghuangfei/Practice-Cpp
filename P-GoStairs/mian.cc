#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

int main () {
  int N , M;
  while ( cin >> N >> M  ) {
    vector<int> stairs (M + 1 , 0x7fffffff);
    stairs [N] = 0;
    for ( int i = N; i <= M; i++  ) {
      if ( stairs [i] == 0x7fffffff  )
        continue;
      for ( int j = 2; (j*j) <= i; j++  ) {
        if ( i%j == 0  ) {
          if ( i + j <= M  )
            stairs [i + j] = min (stairs [i] + 1 , stairs [i + j]);
          if ( (i + (i / j)) <= M  )
            stairs [i + (i / j)] = min (stairs [i] + 1 , stairs [i + (i / j)]);

        }

      }

    }
    if ( stairs [M] == 0x7fffffff  )
      cout << -1 << endl;
    else
      cout << stairs [M] << endl;

  }
  return 0;

}
