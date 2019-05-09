#include<iostream>
#include<vector>
using namespace std;
class Solution {
  public:
    int thirdMax(vector<int>& nums) {
      int Max = INT_MIN,mid = INT_MIN,back = INT_MIN;
      int flag = 1;
      for(int i = 0;i<nums.size();i++){
        if(nums[i]==INT_MIN){
          flag=0;
        }
        if(Max<=nums[i]){
          if(nums[i]!=Max){
            back = mid;
            mid = Max;
            Max = nums[i];
          }
        }else if(mid<=nums[i]){
          if(nums[i]!=mid){
            back = mid;
            mid = nums[i];
          }
        }else if(back<nums[i]){
          back = nums[i];
        }
      }
      int count = 0;
      if(Max!=INT_MIN)
        count++;
      if(mid!=INT_MIN)
        count++;
      if(back!=INT_MIN||!flag)
        count++;
      if(back== INT_MIN){
        if(flag||(!flag&&count<3))
          return Max;
      }
      return back;
    }
};

int mian(){
  int arr[]={1,3,2,5,6,7,9};
  vector<int> a(arr,arr+sizeof(arr)/sizeof(arr[0]));
  Solution test;
  cout<<test.thirdMax(a)<<endl;
}
