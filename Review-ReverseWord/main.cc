#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
  public:
    string ReverseSentence (string str) {
      reverse (str.begin () , str.end ());
      int start = 0 , pos = 0;
      for ( ;; ) {
        pos = str.find (' ' , start);
        if ( pos == string::npos  )
          break;
        reverse (str.begin () + start , str.begin () + pos);
        start = pos + 1;

      }
      reverse (str.begin () + start , str.end ());
      return str;

    }

};
int main () {
  string in ("student am i");
  Solution test;
  string a=test.ReverseSentence (in);
  return 0;

}
