class Solution {
  public:
    int jumpFloorII(int number) {
      int init[3]={0,1,2};
      vector<int> ways(init,init+3);
      if(number >2){
        for(int i = 3;i<=number;i++){
          int in = 0;
          for(auto e:ways)
            in+=e;
          ways.push_back(in+1);

        }

      }
      return ways[number];

    }

};
