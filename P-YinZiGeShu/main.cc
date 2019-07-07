// write your code here cpp
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void DigitNum(vector<int>& back,int& num){
  for(int i= 2;i*i<=num;i++){
    if(num%i==0){
      back.push_back(i);
      num/=i;
      DigitNum(back,num);
      break;
    }
  }
  return;
}

int main(){
  int num;
  while(cin>>num){
    vector<int> all;
    DigitNum(all,num);
    if(num!=1)
      all.push_back(num);
    sort(all.begin(),all.end());
    int count=0;
    for(size_t i = 0;i<all.size();++i){
      if(i==0)
        count++;
      else{
        if(all[i-1]!=all[i])
          count++;
      }
    }
    cout<<count<<endl;
  }
  return 0;
}
}
}
}
}
}
}
}
