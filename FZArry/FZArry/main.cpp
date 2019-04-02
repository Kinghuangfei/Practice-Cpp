#include<iostream>
using namespace std;
int main () {
	int n , m;
	while ( cin >> n >> m ) {
		int group = n / (2 * m);
		long long a = m*m;
		long long back = a*group;
		cout << back << endl;
	}
	return 0;
}
