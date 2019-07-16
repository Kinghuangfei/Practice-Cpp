#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

void Re (string& s , int start , int end) {
  while ( start<end  ) {
    char tmp = s [start];
    s [start] = s [end];
    s [end] = tmp;
    start++;
    end--;

  }

}

int main () {
  string s;
  while ( getline (cin , s)  ) {
    reverse (s.begin () , s.end ());
    for ( size_t i = 0; i<s.size (); i++  ) {
      if ( (s [i]>='a'&&s [i]<='z') || (s [i]>='A'&&s [i]<='Z')  )
        continue;
      s [i] = ' ';

    }
    int start = 0 , end = 0;
    while ( (end = s.find (' ' , start)) != string::npos  ) {
      Re (s , start , end - 1);
      start = end + 1;

    }
    Re (s , start , s.size () - 1);
    cout << s << endl;

  }
  return 0;

}
