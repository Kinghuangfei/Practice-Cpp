#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class StackOnly {
	public:
	static StackOnly CreateObject () {
		return StackOnly ();//��ֵû���⣻
	}
	//StackOnly () {}
	private:
	StackOnly () {}//�ṩΨһͨ���������ǿ���
				   //void* operator new(size_t size) = delete;
				   // void operator delete(void* p)= delete;
};
int main () {
	StackOnly p1 = StackOnly::CreateObject ();
	return 0;
}