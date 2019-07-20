#include<iostream>
#include<vector>

using namespace std;

int main(){
  int num;
  while(cin>>num){
    vector<int> stus(num);
    int k,d;
    for(int i=0;i<num;i++){
      cin>>stus[i];

    }
    cin>>k>>d;
    vector<vector<long> > dp_max(num+1,vector<long>(k+1,0));
    vector<vector<long> > dp_min(num+1,vector<long>(k+1,0)); 
    for(int i = 0;i<num;i++){
      dp_max[i+1][1]=stus[i];
      dp_min[i+1][1]=stus[i];

    }
    for(int i=1;i<=num;i++){
      for(int j=2;j<=k;j++){
        for(int pre=i-1;pre>0&&i-pre<=d;pre--){
          dp_max[i][j]=max(dp_max[i][j],max(dp_max[pre][j-1]*stus[i],dp_min[pre][j-1]*stus[i]));
          dp_min[i][j]=min(dp_min[i][j],min(dp_max[pre][j-1]*stus[i],dp_min[pre][j-1]*stus[i]));

        }

      }

    }
    long mul=dp_max[k][k];
    for(int i=k+1;i<=num;i++){
      mul=max(mul,dp_max[i][k]);

    }
    cout<<mul<<endl;

  }
  return 0;

}
