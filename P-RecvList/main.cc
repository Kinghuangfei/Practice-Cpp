// write your code here cpp
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int HasBank(const string& s){
  int flag = 0;
  for(auto e:s){
    if(e==' '||e==','){
      flag=1;
      break;
    }
  }
  return flag;
}

int main(){
  int num;
  while(cin>>num){
    vector<string> all;
    string in;
    getline(cin,in);
    while(num--){
      getline(cin,in);
      all.push_back(in);
    }
    for(size_t i = 0 ;i<all.size();++i){
      if(i!=0)
        cout<<", ";
      if(HasBank(all[i]))
        cout<<"\""<<all[i]<<"\"";
      else
        cout<<all[i];
    }
    cout<<endl;
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
