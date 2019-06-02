#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main () {
  string get;
  while ( getline (cin , get)  ) {
    vector<string> all;
    size_t size = get.size ();
    size_t start = 0 , end = 0 , tail = size - 1;
    for ( auto i = 0; i<size; i++  ) {
      if ( get [i] == '"' ) {
        start = i;
        while ( get [i] != '"'&&i<size )
          i++;
        end = i;
        string in (get , start + 1 , end - 1);
        all.push_back (in);
        start = end + 2;
      }
      if ( i<size&& get [i] == ' '  ) {
        end = i;
        string in (get , start , end - start);
        all.push_back (in);
        start = end + 1;

      }
    }
    string in (get , start , size - start);
    all.push_back (in);
    cout << all.size () << endl;
    for ( auto i = 0; i<all.size (); i++  ) {
      cout << all [i] << endl;

    }
  }
  return 0;
}'"' )
}'"' )
}
}
}
