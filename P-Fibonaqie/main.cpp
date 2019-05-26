#include<iostream>
#include<cmath>

using namespace std;

int Fib (int num) {
  if ( num == 0  )
    return 0;
  if ( num == 1  )
    return 1;
  int a = 0 , b = 1 , c = 0;
  for ( int i = 2; i <= num; i++  ) {
    c = a + b;
    a = b;
    b = c;

  }
  return c;

}

int main () {
  int n;
  cin >> n;
  int cha = 0;
  int cha_last = (int)0x7fffffff;
  int count = 0;
  for (;;) {
    int fib = Fib (count);
    cha = abs (n - fib);
    if (cha>cha_last){
      cout << cha_last << endl;
      return 0;
    }
    cha_last = cha;
    count++;
  }
  return 0;
}

