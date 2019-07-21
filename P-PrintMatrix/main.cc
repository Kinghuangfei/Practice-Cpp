class Printer {
  public:
    vector<int> clockwisePrint(vector<vector<int> > mat, int n, int m) {
      write code here
        vector<int> back;
      int action[]={0,1,0,-1},sx=0,sy=1;//动作指针与偏移量获取坐标；
      int dx=action[sx],dy=action[sy];//偏移量
      int Flag=INT_MAX;//遍历过的标记
      for(int i=0,x=0,y=0;i<n*m;i++){
        back.push_back(mat[x][y]);
        mat[x][y]=Flag;
        int c_x=x+dx,c_y=y+dy;
        if(c_x>n-1||c_y>m-1||c_x<0||c_y<0||mat[c_x][c_y]==Flag){
          sx=(sx+1)%4;
          sy=(sy+1)%4;
          dx=action[sx];
          dy=action[sy];
        }
        x+=dx;
        y+=dy;
      }
      return back;
    }
};

