class Solution {
  public:
    double Power(double base, int exponent) {
      if (exponent==0)
        return 1;
      if(exponent==1)
        return base;
      int p=exponent>0?exponent:-exponent;
      double fina=1.0;
      while(p){//快速幂
        if(p&0x1)
          fina*=base;
        base*=base;
        p>>=1;
      }
      return exponent>0?fina:1/fina;

    }

};
