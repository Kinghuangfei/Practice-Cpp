#include<iostream>
#include<vector>

using namespace std;


void Merge(vector<int>&a,vector<int>&ex,int start,int mid,int end){
  int left=start,right=mid,size=end-start,i=0;
  while(left<mid&&right<end){
    if(a[left]<=a[right])
      ex[i++]=a[left++];
    else 
      ex[i++]=a[right++];
  }
  while(left<mid)
    ex[i++]=a[left++];
  while(right<end)
    ex[i++]=a[right++];
  for(int i=0;i<size;i++)
    a[start+i]=ex[i];
}

void MergeSort(vector<int>& a,int size){
  vector<int> tmp(size,0);
  for(int i =1 ;i<size;i*=2){//几个一组
    for(int j=0;j<size;j+=i*2){//两组一比较
      int left=j,mid=j+i,right=mid+i;
      if(mid>=size)
        break;
      if(right>size)
        right=size;
      Merge(a,tmp,left,mid,right);
    }
  }
}

int main(){
  vector<int> a{1,3,6,2,54,22,6,88,33,63,87,7,324};
  MergeSort(a,a.size());
  for(auto e:a)
    cout<<e<<" ";
  cout<<endl;
  return 0;
}
