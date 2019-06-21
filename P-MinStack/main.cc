#include<iostream>
#include<stack>

using namespace std;
class Solution {
  public:
    stack<int> src;
    stack<int> mi;
    void push(int value) {
      src.push(value);
      if(src.size()==1)
        mi.push(value);
      else{
        int Min = value<mi.top()?value:mi.top();
        mi.push(Min);

      }

    }
    void pop() {
      if(src.size()==0)
        return;
      src.pop();
      mi.pop();

    }
    int top() {
      return src.top();

    }
    int min() {
      return mi.top();

    }

};
