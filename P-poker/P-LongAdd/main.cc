//长整数相加
#include<iostream>
#include<string>
#include <algorithm> 

using namespace std;

void addlast (string& add , string& s , int min) {
  if ( s.size ()>(size_t)min  ) {
    for ( size_t i = (size_t)min; i<s.size (); i++  ) {
      int a = s [i] - '0';
      int up = (a + add [i] - '0')>9 ? 1 : 0;
      char in = (a + add [i] - '0') % 10 + '0';
      add [i] = in;
      add += up + '0';
    }
  }
}

int main () {
  string dest , src;
  while ( cin >> dest >> src  ) {
    int size_dest = dest.size () , size_src = src.size () , min_size = size_dest<size_src ? size_dest : size_src;
    string add ("0");
    reverse (dest.begin () , dest.end ());
    reverse (src.begin () , src.end ());
    for ( int i = 0; i<min_size; i++  ) {
      int a = dest [i] - '0' , b = src [i] - '0';
      int up = ((a + b) + (add [i] - '0'))>9 ? 1 : 0;
      char in = ((a + b) + (add [i] - '0')) % 10 + '0';
      add [i] = in;
      add += up + '0';
    }
    addlast (add , dest , min_size);
    addlast (add , src , min_size);
    reverse (add.begin () , add.end ());
    if ( add [0] == '0'  )
      add.erase (0,1);
    cout << add << endl;
  }
  return 0;
}

}
}
}
}
}
}
