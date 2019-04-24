#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct Node{
  int val;
  vector<Node*> children;
};

class Solution {
  public:
    vector<vector<int> > levelOrder(Node* root) {
      vector<vector<int> > back;
      queue<Node*> level;
      if(!root)
        return back;
      level.push(root);
      while(!level.empty()){
        int count  = level.size();
        vector<int> tmp;
        while(count>0){
          Node* get = level.front();
          tmp.push_back(get->val);
          level.pop();
          for(int i = 0;i<get->children.size();i++){
            if(get->children[i]){
              level.push(get->children[i]);

            }

          }
          count--;

        }
        back.push_back(tmp);

      }
      return back;

    }

};

int main(){
  return 0;
}
