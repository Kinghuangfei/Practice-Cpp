#include<iostream>
#include<string>

using namespace std;

int main () {
  string A , B;
  while ( cin >> A  ) {
    cin >> B;
    int a [128] = { 0  } , b [128] = { 0  } , flag = 1;
    for ( auto e : A  )
      a [e]++;
    for ( auto e : B  )
      b [e]++;
    for ( int i = (int)'A'; i <= (int)'Z'; i++  ) {
      if ( a [i]<b [i]  ) {
        flag = 0;
        break;

      }

    }
    if ( flag  )
      cout << "Yes" << endl;
    else
      cout << "No" << endl;

  }
  return 0;

}
