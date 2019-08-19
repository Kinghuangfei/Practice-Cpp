#include<iostream>
#include<vector>

using namespace std;

void GapSort(vector<int>& a,int size,int gap){
  for(int i=gap;i<size;i++){
    int tmp=a[i],j=i;
    for(j=i-gap;j>=0;j-=gap){
      if(a[j]>tmp)
        a[j+gap]=a[j];
      else 
        break;
    }
    a[j+gap]=tmp;
  }
}

void Shell(vector<int>& a,int size){
  int gap=size;
  while(1){
    gap=gap/3+1;
    GapSort(a,size,gap);
    if(gap==1)
      break;
  }
}

int main(){
  vector<int> a{1,3,5,2,5,7,8,3,8,0};
  Shell(a,a.size());
  for(auto e:a)
    cout<<e<<" ";
  cout<<endl;
  return 0;
}
