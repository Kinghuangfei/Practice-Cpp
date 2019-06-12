#include<iostream>
#include<vector>

using namespace std;

vector<int>& WashPoker(int len,int times,vector<int>& poker){
  vector<int> left(len,0),right(len,0);
  while(times--){
    int signal = 1,left_pos = len-1,right_pos = len-1;
    for(int i = 0;i<len;i++){
      left[i] = poker[i],right[i] = poker[len+i];

    }
    for(int i = len*2-1;i>=0;i--){
      if(signal){
        poker[i] = right[right_pos--],signal = 0;

      }
      else{
        poker[i] = left[left_pos--],signal = 1;

      }

    }

  }
  return poker;

}

int main(){
  int num;
  while(cin>>num){
    for(int i = 0;i<num;i++){
      int len,times;
      cin>>len>>times;
      vector<int> poker(len*2,0);
      for(int j = 0;j<len*2;j++){
        int m;
        cin>>m;
        poker[j] = m;

      }
      WashPoker(len,times,poker);
      int size = (int)poker.size();
      for(int m = 0;m<size;m++){
        cout<<poker[m];
        if(!(i==num-1&&m==(size-1)))
          cout<<' ';

      }
      cout<<endl;

    }


  }
  return 0;

}
