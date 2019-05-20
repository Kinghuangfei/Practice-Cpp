#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n=0;
  while(cin>>n){
    int* arr = new int[3*n];
    int i =0;
    while(i!=n*3){
      cin>>arr[i++];

    }
    sort(arr,arr+3*n);
    long sum = 0;
    for(int i = 1;i<=n;i++){
      sum+=arr[n*3-i*2];

    }
    cout<<sum<<endl;

  }
  return 0;

}
