#include<iostream>
#include<vector>

using namespace std;

void swap(vector<int>& v,int a,int b){
  int tmp=v[a];
  v[a]=v[b];
  v[b]=tmp;
}

int Getflag(vector<int>& a,int start,int end){
  int mid=(start+end)/2;
  if(a[start]>a[mid]){
    if(a[mid]>a[end])
      return mid;
    else{
      if(a[start]>a[end])
        return end;
      else 
        return start;
    }
  }
  else{
    if(a[mid]<a[end])
      return mid;
    else{
      if(a[start]<a[end])
        return end;
      else 
        return start;
    }
  }
  return end;
}

int Split(vector<int>& a,int start,int end){
  int check=a[end],l=start,r=end;
  while(l<r){
    while(l<r&&a[l]<=check)
      l++;
    a[r]=a[l];
    while(l<r&&a[r]>=check)
      r--;
    a[l]=a[r];
  }
  a[l]=check;
  return l;
}

void Go(vector<int>&a,int left,int right){
  if(left>=right)
    return;
  int flag=Getflag(a,left,right);
  swap(a,flag,right);
  int mid=Split(a,left,right);
  Go(a,left,mid-1);
  Go(a,mid+1,right);
}

void QuickSort(vector<int>& a,int size){
  Go(a,0,size-1);
}

int main(){
  vector<int> a{1,4,2,5,7,344,3,6,44,97,33,24,49,2,67,2,8};
  QuickSort(a,a.size());
  for(auto e:a)
    cout<<e<<" ";
  cout<<endl;
  return 0;
}
