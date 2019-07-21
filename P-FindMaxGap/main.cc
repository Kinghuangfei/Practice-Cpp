class MaxGap {
  public:
    int findMaxGap(vector<int> A, int n) {
      write code here
        if(n==0)
          return 0;
      vector<int> Max_z(n),Max_r(n);
      Max_z[0]=A[0];
      Max_r[n-1]=A[n-1];
      for(int i=1;i<n;i++)
        Max_z[i]=A[i]>Max_z[i-1]?A[i]:Max_z[i-1];
      for(int i=n-2;i>=0;i--)
        Max_r[i]=A[i]>Max_r[i+1]?A[i]:Max_r[i+1];
      int Max=abs(Max_r[1]-Max_z[1]);
      for(int i=0;i<n;i++){
        int in=abs(Max_r[i]-Max_z[i]);
        Max=Max>in?Max:in;
      }
      return Max;
    }
};
}
}
}
