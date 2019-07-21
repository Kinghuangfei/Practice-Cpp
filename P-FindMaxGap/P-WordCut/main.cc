class Solution {
  public:
    bool wordBreak(string s, unordered_set<string> &dict) {
      if(s.empty()||dict.empty())
        return false;
      vector<bool> cut(s.size()+1,false);
      cut[0]=true;
      for(size_t i=1;i<=s.size();i++){
        for(size_t j=0;j<i;j++){
          if(cut[j]&&(dict.find(s.substr(j,i-j))!=dict.end())){
            cut[i]=true;
            break;

          }

        }

      }
      return cut[s.size()];

    }

};
