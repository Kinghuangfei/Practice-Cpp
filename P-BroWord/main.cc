#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

bool isBro (string s , string a) {
  if ( (s.size () != a.size ()) || s == a  )
    return false;
  sort (s.begin () , s.end ());
  sort (a.begin () , a.end ());
  if ( s != a  )
    return false;
  return true;

}
