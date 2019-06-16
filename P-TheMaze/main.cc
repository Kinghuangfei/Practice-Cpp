#include<iostream>
#include<vector>

using namespace std;

int action[4][2]={{0,-1},{0,1},{-1,0},{1,0}};//上下左右

struct point{
  int x;
  int y;
  point(int x_=0,int y_=0):x(x_),y(y_){}
  void display(){
    cout<<'('<<x<<','<<y<<')'<<endl;

  }

};

vector<point> Min;
vector<point> go;

void Check(vector<vector<int> >& board,int x,int y,int n,int m){
  point now(x,y);
  go.push_back(now);
  if(x==n&&y==m){
    if(go.size()<=Min.size())
      Min=go;
    return;

  }
  board[x][y]=-1;
  for(int i = 0;i<4;i++){
    int new_x = x+action[i][0];
    int new_y = y+action[i][1];
    if(new_x>=0&&new_x<=n&&
        new_y>=0&&new_y<=m&&
        board[new_x][new_y]!=1&&
        board[new_x][new_y]!=-1){
      Check(board,new_x,new_y,n,m);
      go.pop_back();

    }

  }
  board[x][y]=0;

}

int main(){
  int n,m;
  while(cin>>n>>m){
    Min.clear();
    go.clear();
    vector<vector<int> > board(n,vector<int>(m,0));
    for(int i = 0;i<n;i++){
      for(int j = 0;j<m;j++){
        int num;
        cin>>num;
        if(num)
          board[i][j]=1;

      }

    }
    Min.resize(m*n);
    Check(board,0,0,n-1,m-1);
    for(size_t i = 0;i<Min.size();i++){
      Min[i].display();

    }

  }
  return 0;

}
