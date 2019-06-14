class Gift {
  public:
    int getValue(vector<int> gifts, int n) {
      write code here
        int count = 1;
      int result =gifts[0];
      for(int i = 1;i<n;i++){
        if(result==gifts[i])
          count++;
        else{
          count--;
          if(!count)
            result = gifts[i],count++;
        }
      }
      int fin = 0;
      for(auto s:gifts){
        if(s==result)
          fin++;
      }
      return fin>(n>>1)?result:0;
    }
};
}
}
}
}
}
