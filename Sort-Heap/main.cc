#include<iostream>
#include<vector>

using namespace std;

void swap(vector<int>& v,int a,int b){
  int tmp=v[a];
  v[a]=v[b];
  v[b]=tmp;
}

void AdjustDown(vector<int>&a,int size,int root){
  while(1){
    int left=root*2+1,Max=left,right=root*2+2;
    if(left>=size)
      return;
    if(right<size&&a[right]>a[left])
      Max=right;
    if(a[root]>=a[Max])
      return;
    swap(a,root,Max);
    root=Max;
  }
}


void CreateHeap(vector<int>&a,int size){
  for(int i=((size-1)-1)/2;i>=0;i--){
    AdjustDown(a,size,i);
  }
}

void HeapSort(vector<int>& a,int size){
  CreateHeap(a,size);
  for(int i=0;i<size-1;i++){
    swap(a,0,size-1-i);
    AdjustDown(a,size-1-i,0);
  }
}

int main(){
  vector<int> a{1,3,5,2,7,9,3,6,8};
  HeapSort(a,a.size());
  for(auto e:a)
    cout<<e<<" ";
  cout<<endl;
  return 0;
}
