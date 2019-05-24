#include<iostream>
#include<vector>

using namespace std;

int main() {
  int n , m;
  vector<int> nums;
  cin >> n;
  while ( cin >> m  ) {
    nums.push_back (m);

  }
  int sum = 0 , i;
  int res = INT_MIN;
  for ( i = 0; i<nums.size(); i++  ) {
    if ( sum >= 0  )
      sum += nums [i];
    else
      sum = nums [i];
    res = (sum>res) ? sum : res;

  }
  return res;

}
