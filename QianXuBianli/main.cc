#include<iostream>
#include<string>

using namespace std;

void fun (string mid , string last , int size) {
  if ( size  ) {
    char root = last [size - 1];
    int i = 0;
    for ( ; i<size; ++i  )
      if ( mid [i] == root  )
        break;
    cout << root;
    fun (mid , last , i);
    fun (mid.substr (i + 1) , last.substr (i) , size - i - 1);

  }

}

int main () {
  string mid , last;
  cin >> mid;
  cin >> last;
  fun (mid , last , mid.size ());
  cout << endl;
  return 0;

}

