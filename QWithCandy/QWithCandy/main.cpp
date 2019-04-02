#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int sum (int s , int N) {
	int sum = 0;
	for ( int i = 0; i<N; i++ ) {
		sum += s;
		s = (s + 1) >> 1;
	}
	return sum;
}

int fun (int N , int M) {
	if ( N == 1 ) { return M; }
	int low = 1;
	int high = M - 1;
	while ( low <= high ) {
		int mid = (low + high + 1) >> 1;
		if ( sum (mid , N) == M ) {
			return mid;
		}
		else if ( sum (mid , N)<M ) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return high;
}
int main () {
	int N = 0 , M = 0;
	while ( cin >> N >> M ) {
		int first = fun (N , M);
		cout << first << endl;
	}
	return 0;
}