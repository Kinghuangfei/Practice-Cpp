#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool Big (string& last , string& now) {
  for ( size_t i = 0; i<now.size (); i++  ) {
    if ( now [i]<last [i]  ) {
      return false;

    }
    else if ( now [i]>last [i]  )
      return true;

  }
  return false;

}

bool checkDict (vector<string>& arr) {
  for ( size_t i = 1; i<arr.size (); i++  ) {
    if ( !Big (arr [i - 1] , arr [i])  )
      return false;

  }
  return true;

}

bool checklength (vector<string>& arr) {
  for ( size_t i = 1; i<arr.size (); i++  ) {
    if ( arr [i].size ()<arr [i - 1].size ()  ) {
      return false;

    }

  }
  return true;

}

int main () {
  int n = 0;
  vector<string> arr;
  cin >> n;
  if ( !n  ) {
    cout << "none" << endl;
    return 0;

  }
  arr.resize (n);
  for ( size_t i = 0; i<arr.size (); i++  ) {
    cin >> arr [i];

  }
  bool dict = checkDict (arr);
  bool length = checklength (arr);
  if ( dict&&length  )
    cout << "both" << endl;
  else if ( dict  )
    cout << "lexicographically" << endl;
  else if ( length  )
    cout << "lengths" << endl;
  else
    cout << "none" << endl;
  return 0;

}

