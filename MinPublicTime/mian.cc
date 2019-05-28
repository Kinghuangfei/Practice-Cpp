#include<iostream>

using namespace std;

int main () {
  int A = 0 , B = 0 , yue_min = 0 , yue_max = -1;
  cin >> A >> B;
  int min = A>B ? B : A;
  int max = A>B ? A : B;
  for ( int i = 1; i <= min; i++  ) {
    if ( (min%i == 0) && (max%i == 0)  )
      yue_max = i;

  }
  if ( yue_max == -1  )
    cout << A*B << endl;
  else
    cout << (A / yue_max)*B << endl;
  return 0;

}
