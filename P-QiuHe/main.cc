#include<iostream>
#include<vector>

using namespace std;

void check(vector<int>& out,int n,int m,int start){
  if(m==0){
    for(size_t i=0;i<out.size();++i){
      i==0?cout<<out[i]:cout<<" "<<out[i];

    }
    cout<<endl;

  }
  for(int i=start;i<=n&&i<=m;i++){
    out.push_back(i);
    check(out,n,m-i,i+1);
    out.pop_back();

  }

}

int main(){
  int n,m;
  while(cin>>n>>m){
    vector<int> out;
    check(out,n,m,1);

  }
  return 0;

}
