#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main () {
  int num , in , time;
  while ( cin >> num  ) {
    vector<int> price (num+1 , 0) , cost (num+1 , 0);
    for ( int i = 1; i<=num; i++  ) {
      cin >> in;
      price [i] = in;
    }
    for ( int i = 1; i<=num; i++  ) {
      cin >> in;
      cost [i] = in;
    }
    cin >> time;
    vector<vector<int>> dp (time+1 , vector<int> (num+1 , 0));
    for ( int i = 1; i<=num; i++  ) {
      if ( cost [i] == 1  ) {
        if ( i == 1  )
          dp [1] [1] = price [1];
        else
          dp [1] [i] = price [i]>dp [1] [i - 1] ? price [i] : dp [1] [i - 1];
      }
    }//初始化0行
    for ( int i = 1; i<=time; ++i  ) {
      if ( cost [1] <= (i + 1)  )
        dp [i] [1] = price [1];
    }//初始化0列；
    for ( int i = 2; i<=time; i++  ) {
      for ( int j = 2; j<=num; j++  ) {
        if ( cost [j]> i  )
          dp [i] [j] = max (dp [i - 1] [j] , dp [i] [j - 1]);
        else {
          dp [i] [j] = max (dp [i- cost [j]] [j - 1] + price [j] , max (dp [i - 1] [j] , dp [i] [j - 1]));
        }
      }
    }
    cout << dp [time] [num] << endl;
  }
  return 0;
}
