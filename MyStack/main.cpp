#include<iostream>
#include<queue>

using namespace std;

class MyStack {
  public:
    /** Initialize your data structure here. */
    MyStack() {


    }

    /** Push element x onto stack. */
    void push(int x) {
      if(frist.empty()&&second.empty())
        frist.push(x);
      else if(!frist.empty())
        frist.push(x);
      else
        second.push(x);

    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
      int val = 0;
      if(!frist.empty()){
        while(frist.size()>1){
          second.push(frist.front());
          frist.pop();

        }
        val = frist.front();
        frist.pop();

      }else{
        while(second.size()>1){
          frist.push(second.front());
          second.pop();

        }
        val = second.front();
        second.pop();

      }
      return val;

    }
    /** Get the top element. */
    int top() {
      int val = 0;
      if(!frist.empty()){
        while(frist.size()>1){
          second.push(frist.front());
          frist.pop();

        }
        val = frist.front();
        second.push(frist.front());
        frist.pop();

      }else{
        while(second.size()>1){
          frist.push(second.front());
          second.pop();

        }
        val = second.front();
        frist.push(second.front());
        second.pop();

      }
      return val;

    }

    /** Returns whether the stack is empty. */
    bool empty() {
      if(frist.empty()&&second.empty())
        return true;
      return false;

    }
  private:
    queue<int> frist;
    queue<int> second;

};

