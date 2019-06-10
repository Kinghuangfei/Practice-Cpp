#include<iostream>
#include<string>
#include<vector>

using namespace std;


int main(){
  string a,b;
  while(cin>>a>>b){
    string max = a.size()>b.size()?a:b,min = a.size()<b.size()?a:b;
    size_t max_len = max.size(),min_len = min.size();
    int longest = 0,start = 0;
    vector< vector<int> > dp(min_len+1,(vector<int>(max_len+1,0)));
    for(size_t i = 1;i<=min_len;i++){
      for(size_t j  =1;j<=max_len;j++){
        if(min[i-1]==max[j-1]){
          dp[i][j]=dp[i-1][j-1]+1;
          if (dp[i][j]>longest){
            longest = dp[i][j];
            start = i-longest;

          }

        }

      }

    }
    cout<<min.substr(start,longest)<<endl;

  }
  return 0;

}
