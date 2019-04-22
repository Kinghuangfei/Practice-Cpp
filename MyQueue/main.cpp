#include<iostream>
#include<stack>

using namespace std;

class MyQueue {
  public:
    /** Initialize your data structure here. */
    MyQueue() {


    }

    /** Push element x to the back of queue. */
    void push(int x) {
      _pushS.push(x);

    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
      if(_popS.empty()){
        while(!_pushS.empty()){
          _popS.push(_pushS.top());
          _pushS.pop();

        }

      }
      int val = _popS.top();
      _popS.pop();
      return val;

    }

    /** Get the front element. */
    int peek() {
      if(_popS.empty()){
        while(!_pushS.empty()){
          _popS.push(_pushS.top());
          _pushS.pop();

        }

      }
      return _popS.top();

    }

    /** Returns whether the queue is empty. */
    bool empty() {
      if(_popS.empty()&&_pushS.empty())
        return true;
      return false;

    }

  private:
    stack<int> _pushS;
    stack<int> _popS;

};

