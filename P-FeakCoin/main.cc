#include<iostream>

using namespace std;

int main () {
  int num;
  while ( cin >> num  ) {
    if ( num == 0  )
      break;
    int count = 1;
    if ( num == 1  )
      count--;
    while ( num>3  ) {
      num = num % 3 == 0 ? num / 3 : num / 3 + 1;
      count++;

    }
    cout << count << endl;

  }
  return 0;

}
