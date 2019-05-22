#include<iostream>

using namespace std;

int main () {
  int fir , sec , thr , fou , A , B , C , flag = 1;
  cin >> fir >> sec >> thr >> fou;
  A = (fir + thr) / 2;
  if ( (fir + thr) % 2  )
    flag = 0;
  B = thr - A;
  C = fou - B;
  if ( flag&&A >= 0 && B >= 0 && C >= 0  ) {
    cout << A << ' ' << B << ' ' << C << endl;

  }
  else {
    cout << "No" << endl;

  }
  return 0;

}
