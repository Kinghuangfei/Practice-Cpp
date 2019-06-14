#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
  string dest,src;
  while(getline(cin,dest)){
    getline(cin,src);
    size_t len1 = dest.size(),len2 = src.size();
    vector<vector<int> >dp(len1+1,vector<int>(len2+1,0));
    for(size_t i = 1;i<=len1;i++){
      dp[i][0]=i;

    }
    for(size_t j = 1;j<=len2;j++){
      dp[0][j]=j;

    }
    for(size_t i = 1;i<=len1;i++){
      for(size_t j = 1;j<=len2;j++){
        int case1=dp[i-1][j-1],case2=dp[i][j-1]+1,case3=dp[i-1][j]+1;//相同，插入,删除；
        if(dest[i-1]!=src[j-1])
          case1+=1;//替换
        int tmp = case1 < case2 ? case1 : case2;
        dp [i] [j] = tmp < case3 ? tmp : case3;

      }

    }
    cout<<dp[len1][len2]<<endl;

  }

}
