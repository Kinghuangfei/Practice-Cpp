#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
  public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
      size_t pvsz = pushV.size();
      size_t popsz = popV.size();
      if(pvsz!=popsz)
        return false;
      stack<int> s;
      size_t pushIndex = 0;
      size_t popIndex = 0;
      while(pushIndex<pvsz){
        s.push(pushV[pushIndex++]);
        while(popIndex<pvsz && s.top()==popV[popIndex]){//不一样就跳过
          s.pop();
          popIndex++;
        }

      }
      return s.empty();

    }

};

int main(){
  Solution test;
  vector<int> pushV(2,6);
  vector<int> popV(6,1);
  test.IsPopOrder(pushV,popV);
  return 0;
}
