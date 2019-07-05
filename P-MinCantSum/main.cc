class Solution {
  public:
    /**
     *   *  正数数组中的最小不可组成和
     *     *  输入：正数数组arr
     *       *  返回：正数数组中的最小不可组成和
     *         */
    int getFirstUnFormedNum(vector<int> arr, int len) {
      vector<int> all;
      int end = pow(2,arr.size())-1;
      for(int i = 1;i<=end;i++){
        int sum = 0;
        for(size_t j = 0;j<arr.size();++j){
          if((i>>j)&1)
            sum+=arr[j];

        }
        all.push_back(sum);

      }
      sort(all.begin(),all.end());
      int last = all[0];
      for(size_t i = 1;i<all.size();++i){
        int cha = all[i]-last;
        if(cha!=0&&cha!=1&&cha!=-1)
          break;
        last = all[i];

      }
      return last+1;

    }

};
