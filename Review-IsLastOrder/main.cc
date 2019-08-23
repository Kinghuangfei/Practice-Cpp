class Solution {
  public:
    bool VerifySquenceOfBST(vector<int> sequence) {
      if(sequence.size()==0)
        return false;
      return Go(sequence);

    }
    bool Go(vector<int> sequence) {
      if(sequence.size()<=1)
        return true;
      int size=sequence.size(),flag=sequence[size-1];
      int i=0;
      for(i=0;i<size-1;++i){
        if(sequence[i]>flag)
          break;

      }
      for(int j=i;j<size-1;j++){
        if(sequence[j]<flag)
          return false;

      }
      auto it=sequence.begin();
      vector<int> L(it,it+i),R(it+i,sequence.end()-1);
      return Go(L)&&Go(R);

    }

};
