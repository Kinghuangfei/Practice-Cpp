//不用加减乘除做加法
class Solution {
  public:
    int Add (int num1 , int num2) {
      int Up = 1;
      while ( Up != 0  ) {
        Up = (num1&num2) << 1;
        num1 ^= num2;
        num2 = Up;
      }
      return num1;
    }
};
}
}
}
