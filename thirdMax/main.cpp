#include<iostream>
#include<vector>
#include<limits.h>

using namespace std; 

class Solution {
  public:
    int thirdMax(vector<int>& nums) {
      int Max = INT_MIN,mid = INT_MIN,back = INT_MIN;
      bool set = false;
      int flag = 0;
      for(int i = 0;i<nums.size();i++){
        if(nums[i]==INT_MIN&&!set){
          flag++;
          set = true;
        }
        if(Max<=nums[i]){
          if(nums[i]!=Max){
            back = mid;
            mid = Max;
            Max = nums[i];
            flag++;
          }
        }else if(mid<=nums[i]){
          if(nums[i]!=mid){
            back = mid;
            mid = nums[i];
            flag++;
          }
        }else if(back<=nums[i]){
          flag++;
          back = nums[i];
        }
      }
      return flag>=3?back:Max;
    }
};

int main(){
  int arr[]={1,3,2,5,6,7,9};
  vector<int> a(arr,arr+sizeof(arr)/sizeof(arr[0]));
  Solution test;
  cout<<test.thirdMax(a)<<endl;
  return 0;
}
