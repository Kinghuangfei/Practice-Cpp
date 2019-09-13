#include<iostream>
#include<vector>
#include<string>

using namespace std;

int act [4] [2] = { { 0 , 1  } , { -1 , 0  } , { 1 , 0  } , { 0 , -1  }  };

int main () {
  int M , N , in;
  string s;
  while ( cin >> M >> N  ) {
    int count = 0;
    int flag = 0;
    vector<vector<int>> board (M , vector<int> (N , 0));
    for ( int i = 0; i<M; i++  ) {
      cin >> s;
      for ( int j = 0; j<N; j++  ) {
        board [i] [j] = s [j] - '0';

      }
      s.clear ();

    }
    for ( int i = 0; i<M; i++  ) {
      for ( int j = 0; j<N; j++  ) {
        if ( board [i] [j] == 1  ) {
          for ( int m = 0; m<4; m++  ) {
            int x = i + act [m] [0] , y = j + act [m] [1];
            if ( x >= 0 && x<M&&y >= 0 && y<N  ) {
              if ( board [x] [y] == 1  ) {
                flag +=1 ;

              }
              else {
                flag = 0;
                break;

              }

            }
            else
              break;

          }
          if ( flag==4  ) 
            count++;
          flag = 0;

        }

      }

    }
    cout << count << endl;

  }
  return 0

}
