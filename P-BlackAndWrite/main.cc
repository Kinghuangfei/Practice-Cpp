#include<iostream>
#include<vector>

using namespace std;

int Max = 0 , m , n;
char board [20] [20] = { 0  };
int action [4] [2] = { { -1 , 0  } , { 1 , 0  } , { 0 , -1  } , { 0 , 1  }  };

void Check (int x , int y) {
  Max++;
  board [x] [y] = 'U';
  for ( int i = 0; i<4; i++  ) {
    int n_x = x + action [i] [0];
    int n_y = y + action [i] [1];
    if ( (n_x<m&&n_x >= 0) && (n_y<n&&n_y >= 0) && board [n_x] [n_y] == '.'  )
      Check (n_x , n_y);

  }

}

int main () {
  while ( cin >> m >> n  ) {
    int s_x , s_y;
    for ( int i = 0; i<m; i++  ) {
      for ( int j = 0; j<n; j++  ) {
        char in;
        cin >> in;
        if ( in == '@'  )
          s_x = i , s_y = j;
        board [i] [j] = in;

      }

    }
    Check (s_x , s_y);
    cout << Max << endl;
    Max = 0;

  }
  return 0;

}

