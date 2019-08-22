class Solution {
  public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
      vector<int> back;
      int act[]={0,1,0,-1};
      int FLAG=(int)0x7fffffff;
      int line=matrix.size(),row=matrix[0].size();
      int a_x=0,a_y=1;
      for(int x=0,y=0,i=0;i<line*row;i++){
        back.push_back(matrix[x][y]);
        matrix[x][y]=FLAG;
        int cx=x+act[a_x],cy=y+act[a_y];
        if(cx>line-1||cx<0||cy>row-1||cy<0||matrix[cx][cy]==FLAG){
          a_x=(a_x+1)%4;
          a_y=(a_y+1)%4;

        }
        x=x+act[a_x];
        y=y+act[a_y];

      }
      return back;

    }

};
