#include<iostream>
#include<string>

using namespace std;

int main () {
  string arr("abcd12345ed125ss123456789");
  while ( cin >> arr  ) {
    string maxsub;
    string temp;
    string::iterator go;
    for ( go = arr.begin () ; go< arr.end (); go++  ) {
      while ( go<arr.end()&&*go >= '0'&&*go <= '9'  ) {
        temp += *go;
        go++;

      }
      if ( temp.size () > maxsub.size ()  ) { maxsub = temp;  }
      temp.clear ();
      if ( go >=arr.end ()  ) { break;  }

    }
    cout << maxsub << endl;

  }
  system ("pause");
  return 0;

}
