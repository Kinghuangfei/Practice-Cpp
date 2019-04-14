#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int hashtab[32] = {0};
        int back = 0;
        for(int j =0 ;j<nums.size();j++){
            int a = 1;
            for(int i = 0;i<32;i++){
                if(nums[j]&(a<<i)){
                    hashtab[i]++;
                }
            }
        }
        for(int i =0;i<31;i++){
            if(hashtab[i]%3){
                back+=pow(2,i);
            }
        }
        if (hashtab[31]%3){
            back+=0x80000000;
        }
        return back;
    }
};

int main(){
  Solution test;
  int arr[]={-1,-2,-3,-5,-3,-2,-1,-2,-3,-1};
  vector<int> a(arr,arr+sizeof(arr)/sizeof(arr[0]));
  cout<<test.singleNumber(a)<<endl;

  return 0;
}
