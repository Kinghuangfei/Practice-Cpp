#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int act [4][2] = {{0,1}, {1,0 } , {0 ,-1 },{-1,0}};
struct pos{
  pos(int _x,int _y,int _count):x(_x),y(_y),count(_count){}
  int x,y,count;

};

int CountPath (vector<vector<char>>& board) {
  vector<vector<bool> > visit(10, vector<bool>(10, false));
  queue<pos> all;
  pos start(0,1,0),end(9,8,0);
  all.push(start);
  visit[start.x][start.y]=true;
  while(!all.empty()){
    pos fir=all.front(),next(0,0,0);
    all.pop();
    for ( int i = 0; i<4; i++  ) {
      next.x= fir.x + act [i] [0];
      next.y = fir.y+ act [i] [1];
      next.count=fir.count+1;
      if(next.x==9&&next.y==8)
        return next.count;
      if ( next.x>=0 && next.x<10 && next.y>=0 && next.y<10 && board[next.x][next.y] == '.'&&(!visit[next.x][next.y]) ) {
        all.push(next);
        visit[next.x][next.y]=true;

      }

    }

  }
  return 0;

}


int main () {
  vector<vector<char>> board (10 , vector<char> (10));
  char in;
  while (cin >> board[0][0])
  {
    for (int i = 0; i < 10; ++i){
      for (int j = 0; j < 10; ++j)
      {
        if (i == 0 && j == 0) continue;
        cin >> board[i][j];

      }

    }
    cout<<CountPath(board)<< endl;

  }
  return 0;

}
