class Solution {
  public:
    int maxChunksToSorted(vector<int>& arr) {
      stack<int> s;
      s.push(arr[0]);
      for(int i=1;i<arr.size();++i){
        if(arr[i]>s.top())
          s.push(arr[i]);
        else{
          int top=s.top();
          while((!s.empty())&&arr[i]<s.top())
            s.pop();
          s.push(top);

        }

      }
      return s.size();

    }

};
