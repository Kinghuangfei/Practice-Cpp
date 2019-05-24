#include<iostream>
#include<string>
using namespace std;

void CheckHW (string& str , int* count) {
  size_t start = 0 , end = str.size () - 1;
  int flag = 1;
  while ( start<end  ) {
    if ( str [start] != str [end]  ) {
      flag = 0;
      break;

    }
    start++;
    end--;

  }
  if ( flag  )
    ++(*count);

}

int main () {
  string dest , src , newr;
  int count = 0;
  cin >> dest;
  cin >> src;
  for ( int i = 0; i<=dest.size (); i++  ) {
    newr = dest;
    newr.insert (i , src);
    CheckHW (newr , &count);
    newr.clear ();

  }
  cout << count << endl;
  return 0;

}
