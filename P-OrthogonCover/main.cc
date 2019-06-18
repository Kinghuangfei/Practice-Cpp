class Solution {
  public:
    int rectCover(int number) {
      if(number==1)
        return 1;
      if(number==2)
        return 2;
      int a = 1,b=2,c=0;
      for(int i = 3;i<=number;i++){
        c = a+b;
        a = b;
        b = c;

      }
      return c;

    }

};
