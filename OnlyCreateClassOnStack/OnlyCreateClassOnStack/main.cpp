#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class StackOnly {
	public:
	static StackOnly CreateObject () {
		return StackOnly ();//传值没问题；
	}
	//StackOnly () {}
	private:
	StackOnly () {}//提供唯一通道；不考虑拷贝
				   //void* operator new(size_t size) = delete;
				   // void operator delete(void* p)= delete;
};
int main () {
	StackOnly p1 = StackOnly::CreateObject ();
	return 0;
}