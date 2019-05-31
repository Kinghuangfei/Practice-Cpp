class BinInsert {
  public:
    int binInsert (int n , int m , int j , int i) {
      int count = 0 , bit , add , start = j;
      while ( start <= i  ) {
        bit = m&(1 << count);
        if ( bit  )
          n = n | (1 << count + j);
        else {
          add = 0xffffffff - (1 << (count + j));
          n = n&add;

        }
        count++;
        start++;

      }
      return n;

    }

};
