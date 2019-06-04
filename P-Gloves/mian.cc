#include<iostream>
#include<vector>
using namespace std;
class Gloves {
  public:
    int findMinimum (int n , vector<int> left , vector<int> right) {
      int left_all = 0 , right_all = 0 , left_half = 0 , right_half = 0;
      int left_double_small = -1 , right_double_small = -1 , signal1 = 1 , signal2 = 1;//左右手套里成套的最少的；
      for ( int i = 0; i<n; i++  ) {
        if ( left [i] == 0  )
          right_half += right [i];//right里有这么多是残缺的；
        else {
          if ( right [i] && (left_double_small>left [i] || signal1)  ) {
            left_double_small = left [i];
            signal1 = 0;

          }
          left_all += left [i];

        }
        if ( right [i] == 0  )
          left_half += left [i];//left里有这么多是残缺的；
        else {
          if ( left [i] && (right_double_small>right [i] || signal2)  ) {
            right_double_small = right [i];
            signal2 = 0;

          }
          right_all += right [i];

        }

      }
      int left_main_left = 1 + left_half;//此时必有一个左手套是成双的；
      int left_main_right = right_all - right_double_small + 1;//从第二个有效数变成1
      int left_main = left_main_left + left_main_right;
      int right_main_right = 1 + right_half;//此时必有一个右手套是成双的
      int right_main_left = left_all - left_double_small + 1;
      int right_main = right_main_right + right_main_left;
      return right_main<left_main ? right_main : left_main;

    }

};

