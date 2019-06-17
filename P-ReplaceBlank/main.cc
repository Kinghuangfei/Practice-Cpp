#include<iostream>
#include<string>
#include<cstring>
using namespace std;
class Solution {
  public:
    void replaceSpace (char *str , int length) {
      string  s (str);
      size_t fin = 0;
      while ( (fin = s.find (' ' , fin)) != string::npos  ) {
        s.erase (fin , 1);
        s.insert (fin , "%20");

      }
      strcpy (str , s.c_str ());

    }

};
int main () {
  Solution  test;
  char* arr = "hello world";
  test.replaceSpace (arr , 0);
  cout << arr << endl;
  system ("pause");
  return 0;

}
