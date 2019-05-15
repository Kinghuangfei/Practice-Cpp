#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    bool Find(int target, vector<vector<int> > array) {
      int line = array[0].size();
      int row = array.size();
      for(int i = 0;i<row;i++){
        if(array[i][line-1]>=target){
          for(int j = line-1;j>=0;j--){
            if(array[i][j]==target)
              return true;
          }
        }
      }
      return false;
    }
};

int main(){
  Solution test;
  int arr[4][3]={{2,4,6},{7,8,9},{11,13,14},{16,18,19}};
  vector<vector<int> > array;
  for(int i=0;i<4;i++){
    vector<int> ret(arr[i],arr[i]+2);
    array.push_back(ret);
  }
  cout<<test.Find(16,array)<<endl;
  return 0;
}
