#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      vector<vector<int>> back;
      int nums_num = nums.size();
      if(nums_num<3)
        return back;
      sort(nums.begin(),nums.end());//排序
      int zero_pos = -1,zero_nums = 0,zhengshu_pos = -1;
      for(int i = 0;i<nums_num;i++){//确定第一个0位置，第一个正数位置，零的个数
        if(nums[i]==0){
          if(zero_pos==-1)
            zero_pos = i;
          zero_nums++;
        }
        if(nums[i]>0&&zhengshu_pos==-1)
          zhengshu_pos = i;
      }
      if(zero_pos==-1&&zhengshu_pos==-1){//全负数
        return back;
      }
      if(zero_pos==0&&zero_nums>=3){//最小数是0所以只有000一种情况
        back.push_back({0,0,0});
        return back;
      }
      if(zhengshu_pos==-1&&zero_pos>0){//最大数是0，所以也只有000一种情况
        if(zero_nums>=3)
          back.push_back({0,0,0});
        return back;
      }
      int first = 0,mid = 0,end = 0;
      int left_end = (zero_pos==-1)?zhengshu_pos:zero_pos;
      for(int j = 0;j<left_end;j++){
        first = nums[j];
        if(j>0&&first==nums[j-1]){
          continue;//头去重；
        }
        int mid_pos = j+1;
        int end_pos = nums_num-1;
        while(mid_pos<end_pos){
          mid  = nums[mid_pos];
          if(mid_pos>(j+1)&&nums[mid_pos]==nums[mid_pos-1]){
            mid_pos++;
            continue;
            break;
          }//中间去重；
          end = nums[end_pos];
          if(first+mid>0)//如果first+mid>0证明第三个数是啥结果都会大于0（end>=0）
            break;
          if(first+mid == -end){
            back.push_back({first,mid,end});
            mid_pos++;
            end_pos--;
          }else if(first+mid>-end)
            end_pos--;
          else if(first+mid<-end)
            mid_pos++;
        }
      }
      if(zero_pos>0&&zero_nums>=3)//别忘了000情况;
      back.push_back({0,0,0});
      return back;
    }
};

int main(){
  int arr[] = {-1,-1,0,-2,3,4,0,0};
  int size = sizeof(arr)/sizeof(arr[0]);
  vector<int> nums(arr,arr+size-1);
  Solution test;
  vector<vector<int> > result(test.threeSum(nums));
  return 0;
}
