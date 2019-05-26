//合法括号序列判断
#include<iostream>
#include<string>
#include<stack>

using namespace std;
class Parenthesis {
  public:
    bool chkParenthesis (string A , int n) {
      stack<char> judge;
      for ( int i = 0; i<n; i++  ) {
        if ( A [i] == '(' )
          judge.push (A [i]);
        else if ( A [i] == ')'  ) {
          if ( judge.empty ()  )
            return false;
          judge.pop ();
        }
        else
          return false;
      }
      if ( judge.empty ()  )
        return true;
      return false;
    }
};
