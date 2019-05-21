#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

void Swap (string& arr , size_t start , size_t pos) {
  char temp = arr [start];
  arr [start] = arr [pos];
  arr [pos] = temp;

}

void Reverse (string& arr , size_t start , size_t pos) {
  while ( start<pos  ) {
    Swap (arr , start , pos);
    start++;
    pos--;

  }

}

int main () {
  string arr;
  while ( getline (cin , arr)  ) {
    size_t start = 0 , end = arr.size () - 1 , pos;
    Reverse (arr , start , end);
    while ( (pos = arr.find (' ' , start)) != -1  ) {
      Reverse (arr , start , pos - 1);
      start = pos + 1;

    }
    Reverse (arr , start , end);
    cout << arr << endl;

  }
  return 0;

}
