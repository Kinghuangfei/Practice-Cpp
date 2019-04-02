//牛牛和羊羊正在玩一个纸牌游戏。这个游戏一共有n张纸牌, 第i张纸牌上写着数字ai。牛牛和羊羊轮流抽牌 , 牛牛先抽 , 每次抽牌他们可以从纸牌堆中任意选择一张抽出 , 直到纸牌被抽完。他们的得分等于们抽到的纸牌数字总和。现在假设牛牛和羊羊都采用最优策略 , 请你计算出游戏结束后牛牛得分减去羊羊得分等于多少。
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
void Merge (int start , int end , int mid , int*arr , int* tmp) {
	int Size = end - start;
	int left_index = start;
	int right_index = mid;
	int tmp_index = 0;
	while ( left_index<mid && right_index<end ) {
		if ( arr [left_index] <= arr [right_index] ) {
			tmp [tmp_index] = arr [left_index++];
		}
		else {
			tmp [tmp_index] = arr [right_index++];
		}
		tmp_index++;
	}
	while ( left_index<mid ) {
		tmp [tmp_index++] = arr [left_index++];
	}
	while ( right_index<end ) {
		tmp [tmp_index++] = arr [right_index++];
	}
	for ( int i = 0; i<Size; i++ ) {
		arr [start + i] = tmp [i];
	}
}
void _Sort (int * arr , int left , int right , int* tmp) {
	if ( left >= right - 1 ) {
		return;
	}
	int mid = left + (right - left) / 2;
	_Sort (arr , left , mid , tmp);
	_Sort (arr , mid , right , tmp);
	Merge (left , right , mid , arr , tmp);
}

void sort (int*arr , int arrSize) {
	int* tmp = new int [arrSize];
	_Sort (arr , 0 , arrSize , tmp);
	delete[] tmp;
}
int main () {
	int n = 0 , i = 0;
	while ( cin >> n ) {
		int* arr = new int [n];
		while ( i != n ) {
			cin >> arr [i++];
		}
		sort (arr , n);
		int back = 0 , car = 1 , num = n - 1;
		while ( num >= 0 ) {
			back += car*arr [num];
			car *= (-1);
			num--;
		}
		delete[] arr;
		cout << back << endl;
	}
	return 0;
}