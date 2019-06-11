#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
  string fir,sec;
  while(cin>>fir>>sec){
    int max=0;
    size_t fir_len=fir.size(),sec_len=sec.size();
    vector<vector<int> >dp(fir_len+1,vector<int>(sec_len+1,0));
    for(size_t i = 1;i<=fir_len;i++){
      for(size_t j =1;j<=sec_len;j++){
        if(fir[i-1]==sec[j-1]){
          dp[i][j]=dp[i-1][j-1]+1;
          if(dp[i][j]>max)
            max = dp[i][j];

        }

      }

    }
    cout<<max<<endl;

  }
  return 0;

}
