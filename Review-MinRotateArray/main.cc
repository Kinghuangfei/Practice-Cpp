class Solution {
  public:
    int minNumberInRotateArray(vector<int> rotateArray) {//注意用二分查找的思想来使复杂度到O(logn);
      if(!rotateArray.size())
        return 0;
      int left=0,right=rotateArray.size()-1;
      while(left<right){
        if(rotateArray[left]<rotateArray[right])
          return rotateArray[left];
        int mid=left+(right-left)/2;
        if(rotateArray[left]<rotateArray[mid])
          left=mid+1;
        else if(rotateArray[mid]<rotateArray[right])
          right=mid;
        else
          left++;//三组数据相等，减小范围吧！{2,2,2,2,0,1,2,2,2};

      }
      return rotateArray[left];

    }

};
