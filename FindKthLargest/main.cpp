#include<iostream>
#include<vector>
#include<priority_queue>

using namespace std;

class Solution {
  public:
    int findKthLargest(vector<int>& nums, int k) {
      priority_queue<int> pq;
      for(const auto& e:nums)
        pq.push(e);
      for(int i = 0;i<k-1;i++)
        pq.pop();
      return pq.top();

    }

};

int main(){
  return 0;
}
