class Solution {
  public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
      if(numbers.size()==0)
        return 0;
      int count =1;
      int back = numbers[0];
      for(size_t i = 1;i<numbers.size();i++){
        if(back==numbers[i])
          ++count;
        else {
          --count;
          if(count==0){
            back=numbers[i];
            count=1;

          }

        }

      }
      count=0;
      for(auto e:numbers){
        if(e==back)
          count++;

      }
      return count>(numbers.size()/2)?back:0;

    }

};
