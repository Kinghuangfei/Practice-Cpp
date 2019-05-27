#include<iostream>
#include<vector>
using namespace std;

int BJ (int h , int w) {
  int row_yu = w % 4>2 ? 2 : w % 4;
  int cakeAline = w / 4 * 2 + row_yu;
  if ( h % 4>2  )
    return cakeAline * 2 + (w - cakeAline);
  else
    return cakeAline*(h % 4);

}

int main () {
  int h , w;
  cin >> h >> w;
  int count = 0;
  int block = (h / 4)*(w / 4)*(4 * 4 / 2);
  int line_BJ = BJ (h , w);
  int row_BJ = (h / 4 * 2)*(w % 4);
  count = block + line_BJ + row_BJ;
  cout << count << endl;
  return 0;

}

