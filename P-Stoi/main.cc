#include<iostream>
#include<string>
#include<cmath>

using namespace std;

class Solution {
  public:
    int StrToInt (string str) {
      if ( str.size ()<1  )
        return 0;
      int flag = 0 , cha = 0 , count = 0;
      if ( str [0] == '-'  ) {
        flag = 1;
        cha = 1;

      }
      else if ( str [0] == '+'  ) {
        cha = 1;

      }
      for ( size_t i = 0; i<str.size (); i++  ) {
        if ( i == 0 && cha  )
          continue;
        if ( str [i]>'9' || str [i]<'0'  )
          return 0;
        count = count * 10 + (str [i] - '0');

      }
      count *= pow (-1 , flag);
      return count;

    }

};

