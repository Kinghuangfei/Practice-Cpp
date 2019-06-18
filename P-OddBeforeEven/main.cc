class Solution {
  public:
    void reOrderArray(vector<int> &array) {
      int start = 0;int end = array.size()-1;
      vector<int>::iterator a = array.begin();
      for(size_t j=0,i = 0;j<end+1;j++){
        if(array[i]%2==0){
          int count = array[i];
          array.erase(array.begin()+i);
          array.push_back(count);
        }else{
          i++;
        }
      }
    }
};i
}
}
}
}
}
