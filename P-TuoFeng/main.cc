#include<iostream>
#include<string>

using namespace std;

int main () {
  string s;
  while ( getline (cin , s)  ) {
    int flag = 0;
    for ( size_t i = 0; i<s.size (); ) {
      if ( s [i] == '_'  ) {
        flag = 1;
        s.erase (i , 1);
        continue;

      }
      else if ( flag  ) {
        s [i] -= 32;
        flag = 0;

      }
      i++;

    }
    cout << s << endl;

  }
  return 0;

}
