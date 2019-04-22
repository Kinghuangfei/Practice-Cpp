#include<iostream>
#include<vector>
#include<stack>
#include<cstdlib>
//using namespace std;

class Solution {
  public:
    int evalRPN(std::vector<std::string>& tokens) {
      std::stack<int> s;
      for(int i = 0;i<tokens.size();i++){
        if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"){
          int right = s.top();//最先取出右操作数
          s.pop();
          int left = s.top();
          s.pop();
          switch(tokens[i][0]){
            case '+':
              s.push(left+right);
              break;
            case '-':
              s.push(left-right);
              break;
            case '*':
              s.push(left*right);
              break;
            case '/':
              s.push(left/right);
              break;

          }

        }else{
          s.push(atoi(tokens[i].c_str()));

        }

      }
      return s.top();

    }

};//操作数入栈，遇到操作符，从栈中去除操作符需要的操作数，取出操作数的位置上应该为从右向左，进行运算，运算结果继续压栈，重复，最后返回栈顶即为结果



int main(){
  Solution test;
  std::vector<std::string> a;
  a[0]="2";
  a[1]="1";
  a[2]="+";
  test.evalRPN(a);
  return 0;
}
