class Solution {
  public:
    /**
     *      *  奇数位上都是奇数或者偶数位上都是偶数
     *           *  输入：数组arr，长度大于2
     *                *  len：arr的长度
     *                     *  将arr调整成奇数位上都是奇数或者偶数位上都是偶数
     *                          */
    void oddInOddEvenInEven(vector<int>& arr, int len) {
      int fir = 0,sec=1;
      while(fir<len&&sec<len){
        if(arr[len-1]%2==0){
          swap(arr[len-1],arr[fir]);
          fir+=2;

        }else{
          swap(arr[len-1],arr[sec]);
          sec+=2;

        }

      }

    }

};
