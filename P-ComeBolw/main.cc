#include<iostream>
#include<string>
#include <algorithm>

using namespace std;

void goUp (string& a , int i , int add) {
  if ( i == a.size ()  )
    a += "0";
  int num = a [i] - '0' + add;
  int bit = num / 10;
  if ( num>9  ) {
    a [i] = num - 10 * bit + '0';
    if ( i == ((int)a.size () - 1)  ) {
      a += "0";

    }
    a [i + 1] += bit;

  }
  else {
    a [i] = num + '0';

  }

}

void Digit (double sum , int& a , int& b , int& c) {
  sum *= 100;
  a = sum / 100;
  b = sum / 10 - a * 10;
  c = sum - a * 100 - b * 10;

}

string ZhouChang (string& a) {
  string back ("0");
  for ( int i = (int)a.size () - 1 , j = 0; i >= 0; --i , ++j  ) {
    double get = (a [i] - '0')*6.28;
    int one = 0 , two = 0 , three = 0;
    Digit (get , one , two , three);
    goUp (back , j , one);
    if ( j - 1 >= 0  )
      goUp (back , j - 1 , two);
    if ( j - 2 >= 0  )
      goUp (back , j - 2 , three);

  }
  reverse (back.begin () , back.end ());
  return back;

}

bool checkBigger (string& cat , string& b) {
  int cat_size = (int)cat.size () , b_size = (int)b.size ();
  if ( cat_size<b_size  )
    return false;
  else if ( cat_size>b_size  )
    return true;
  else {
    for ( size_t i = 0; i<cat.size (); ++i  ) {
      if ( cat [i]<b [i]  )
        return true;
      else if ( cat [i]>b [i]  )
        return false;

    }

  }
  return true;

}

int main () {
  string len , r;
  while ( cin >> len >> r  ) {

    string back = ZhouChang (r);
    if ( checkBigger (len , back)  )
      cout << "Yes" << endl;
    else
      cout << "No" << endl;

  }
  return 0;

}


#include<iostream>

using namespace std;

int main(){
  double a,b;
  while(cin>>a>>b){
    bool check=a>b*6.18?0:1;
    if(check)
      cout<<"Yes"<<endl;
    else
      cout<<"No"<<endl;

  }
  return 0;

}

