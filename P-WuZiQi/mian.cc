// write your code here cpp
#include<iostream>
#include<vector>

using namespace std;

int act[8][2]={{-1,-1},{0,-1},{1,-1},{-1,0},{1,0},{-1,1},{0,1},{1,1}};

struct pos{
  pos(int _x,int _y):x(_x),y(_y){}
  int x;
  int y;
};

void check(const vector<vector<char>>&board,int x,int y,int i,int& count){
  count++;
  int n_x=x+act[i][0],n_y=y+act[i][1];
  if(n_x>=0&&n_x<20&&n_y>=0&&n_y<20&&board[x][y]==board[n_x][n_y])
    check(board,n_x,n_y,i,count);
}

int main(){
  char first;
  while(cin>>first){
    vector<vector<char>> board(20,vector<char>(20,'.'));
    vector<pos> c;
    if(first!='.'){
      board[0][0]=first;
      pos n(0,0);
      c.push_back(n);
    }
    for(int i=1;i<20;i++){
      char in;
      cin>>in;
      if(in!='.'){
        board[0][i]=in;
        pos n(0,i);
        c.push_back(n);
      }
    }
    for(int i=1;i<20;i++){
      for(int j=0;j<20;j++){
        char in;
        cin>>in;
        if(in!='.'){
          board[i][j]=in;
          pos n(i,j);
          c.push_back(n);
        }
      }
    }
    int flag=1;
    for(auto e:c){
      int x=e.x,y=e.y,i=0;
      for(i=0;i<8;i++){
        int count=0;
        check(board,x,y,i,count);
        if(count==5){
          cout<<"Yes"<<endl;
          flag=0;
          break;
        }
      }
      if(!flag)
        break;
    }
    if(flag)
      cout<<"No"<<endl;
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
}
}
}
}
}
