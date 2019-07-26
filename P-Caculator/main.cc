#include<iostream>
#include<stack>
#include<string>
#include<vector>

using namespace std;

int main () {
  string get;
  int num;
  while ( cin >> num  ) {
    stack<int> c;
    vector<string> all;
    while(num--){
      cin>>get;
      all.push_back(get);

    }
    for ( auto e : all  ) {
      if ( e [0] >= '0'&&e [0] <= '9'  )
        c.push (atoi (e.c_str ()));
      else {
        int a = c.top ();
        c.pop ();
        int b = c.top ();
        c.pop ();
        if ( e == "+"  )
          c.push (a + b);
        else if ( e == "-"  )
          c.push (b- a);
        else if ( e == "*"  )
          c.push (a*b);
        else if ( e == "/"  )
          c.push (b/a);

      }

    }
    cout << c.top () << endl;

  }
  return 0;

}
