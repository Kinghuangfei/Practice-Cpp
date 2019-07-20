//简单错误记录
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main () {
  vector<string> all;
  vector<int> count;
  string file , length;
  while ( cin >> file  ) {
    cin >> length;
    int flag = 1;
    size_t pos = file.rfind ('\\');
    if ( pos != string::npos  )
      file = file.substr (pos + 1);
    if ( file.size ()>16  )
      file = file.substr (file.size () - 16);
    string fin = file + " " + length;
    if ( all.size () == 0  ) {
      all.push_back (fin);
      count.push_back (1);
    }
    else {
      for ( size_t i = 0; i<all.size (); i++  ) {
        if ( all [i] == fin  ) {
          count [i]++ , flag = 0;
        }
      }
      if ( flag  ) {
        all.push_back (fin);
        count.push_back (1);
      }
      flag = 1;
    }
  }
  size_t i = 0;
  if ( all.size ()>8  )
    i = all.size () - 8;
  for ( ; i<all.size (); i++  ) {
    cout << all [i] << " " << count [i] << endl;
  }
  return 0;
}

