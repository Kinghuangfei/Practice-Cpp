class Solution {
  public:
    int FindGreatestSumOfSubArray(vector<int> array) {
      if(array.size()==0)
        return 0;
      int sum=0,Max=(int)0x80000000;
      for(auto e:array){
        sum=sum>=0?sum:0;
        sum+=e;
        Max=Max>sum?Max:sum;

      }
      return Max;

    }

};
