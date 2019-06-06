//扑克牌断大小
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
unordered_map<char , int> total{ { '3' , 0  } , { '4' , 1  } , { '5' , 2  } , { '6' , 3  } , { '7' , 4  } , { '8' , 5  } , { '9' , 6  } , { '1' , 7  } , { 'J' , 11  } , { 'Q' , 12  } , { 'K' , 13  } , { 'A' , 14  } , { '2' , 15  }  };

string NumTen (string s) {
  string s1 (s);
  while ( s1.find ('0') != string::npos  )
    s1.erase (s1.find ('0') , 1);
  return s1;
}

int main () {
  string src;
  while ( getline (cin , src)  ) {
    string left , right;
    int pos = src.find ('-');
    left = src.substr (0 , pos);
    string left_change = NumTen (left);
    right = src.substr (pos + 1);
    string right_change = NumTen (right);
    if ( left == "joker JOKER" || right == "joker JOKER"  )
      cout << "joker JOKER" << endl;
    else if ( left_change.size () == 7 || right_change.size () == 7  ) {
      string max;
      if ( left_change.size () == 7 && right_change.size () == 7  ) {
        max = total [left_change [0]]>total [right_change [0]] ? left : right;
      }
      else
        max = (left_change.size () == 7) ? left : right;
      cout << max << endl;
    }
    else if ( left_change.size () == right_change.size ()  ) {
      string max = total [left_change [0]]>total [right_change [0]] ? left : right;
      cout << max << endl;
    }
    else
      cout << "ERROR" << endl;
  }
  return 0;
}

}
}
}
}
}
}
