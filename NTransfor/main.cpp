#include<iostream>
#include<stack>
using namespace std;
void Push (stack<char>& arr , int data) {
  if ( data<10  ) {
    char in = '0' + data;
    arr.push (in);

  }
  else {
    char in = 'A' + (data - 10);
    arr.push (in);

  }

}

int main () {
  int M , N , yu , shang , flag = 0;
  cin >> M >> N;
  stack<char> arr;
  if ( M<0  ) {
    M = -M;
    flag = 1;

  }
  do {
    yu = M%N;
    shang = M / N;
    Push (arr , yu);
    M = shang;

  } while ( shang >= N  );
  Push (arr , shang);
  if ( flag  )
    arr.push ('-');
  while ( !arr.empty ()  ) {
    cout << arr.top ();
    arr.pop ();

  }
  cout << endl;
  return 0;

}

