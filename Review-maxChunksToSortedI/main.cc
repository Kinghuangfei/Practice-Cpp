class Solution {
  public:
    int maxChunksToSorted(vector<int>& arr) {
      int Max=-1,back=0;
      for(int i=0;i<arr.size();i++){
        Max=max(Max,arr[i]);
        if(Max<=i)
          back++;

      }
      return back;

    }

};
