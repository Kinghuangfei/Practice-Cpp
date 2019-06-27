class Solution {
  public:
    int BackPos(vector<char> once,string& str){
      if(once.empty())
        return -1;
      for(size_t i = 0;i<str.size();i++){
        for(auto a:once){
          if(a==str[i])
            return i;

        }

      }
      return -1;

    }
    int FirstNotRepeatingChar(string str) {
      int Hash[128]={0};
      vector<char> once;
      for(auto e:str){
        Hash[e]++;

      }
      for(int i = 65;i<=122;i++){
        if(Hash[i]==1)
          once.push_back((char)i);

      }
      return BackPos(once,str);

    }

};
