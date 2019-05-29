#include<stdio.h>

int action [8] [2] = { { -1 , -1  } , { -1 , 0  } , { -1 , 1  } , { 0 , -1  } , { 0 , 1  } , { 1 , -1  } , { 1 , 0  } , { 1 , 1  }  };
bool check (int board[][3] , int i , int j) {
  if ( (i >= 0 && i<3) && (j >= 0 && j<3) && board [i] [j] == 1  )
    return true;
  return false;

}
bool checkwin (int board[][3] , int i , int j) {
  for ( int i = 0; i<8; i++  ) {
    //if(check(board,i+action[i][0],j+action[i][1])&&(check(board,i+(action[i][0])*2,j+(action[i][1])*2)||check(board,i-action[i][0],j-action[i][1])))
    //    if ( check (board , i + action [i] [0] , j + action [i] [1]) && check (board , i + (action [i] [0]) * 2 , j + (action [i] [1]) * 2)  )
    //          return true;
    //            
  }
  return false;

}
bool checkWon (int board[][3]) {
  for ( size_t i = 0; i<3; i++  ) {
    for ( size_t j = 0; j<3; j++  ) {
      if ( board [i] [j] == 1  ) {
        if ( checkwin (board , i , j)  )
          return true;

      }

    }

  }
  return false;

}

int main () {
  int arr[] [3] = { { 1 , 0 , 1  } , { 1 , -1 , -1  } , { 1 , -1 , 0  }  };
  checkWon (arr);
  return 0;

}

