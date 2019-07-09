// write your code here cpp
#include<iostream>

using namespace std;

int Day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int D_M[13]={0,2,1,1,2,1,2,1,2,2,2,1,2};

int main(){
  int  y1,m1,d1;
  while(cin>>y1>>m1>>d1){
    int y2,m2,d2;
    cin>>y2>>m2>>d2;
    int Money = 0,flag = 1;
    if(m2>m1){
      Money = (Day[m1]-d1+1)*D_M[m1];
      if(m1==2&&(y1%400==0||(y1%4==0&&y1%100!=0))){
        Money+=1;
      }
      m1++;
    }else{
      Money = (d2-d1+1)*D_M[m1],flag=0;
    }
    for(;!(y1>=y2&&m1>=m2);m1++){
      if(m1>12){
        m1=1,y1++;
      }
      if(m1==2&&(y1%400==0||(y1%4==0&&y1%100!=0))){
        Money+=1;
      }
      Money+=Day[m1]*D_M[m1];
    }
    if(flag)
      Money+=d2*D_M[m2];
    cout<<Money<<endl;
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
}
