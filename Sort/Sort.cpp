#include<iostream>
#include<cstring>
#include<cassert>

using namespace std;
class Solution {
  public:
    Solution(int* arr=NULL,int size=0)
      :_arr(arr)
       ,_size(size)
  {}
    ~Solution(){
      _arr=NULL;
      _size = 0;
    }
    int* BubbleSort(int* arr,int size){
      for(int i  =0;i<size-1;i++){
        for(int j =0;j<size-i-1;j++){
          if(arr[j]>arr[j+1]){
            Swap(arr+j,arr+j+1);
          }
        }
      }
      return arr;
    }
    int* InsertSort(int* arr,int size){
      for(int i = 1;i<size;i++){
        int temp = arr[i];
        int j = i-1;
        for(;j>=0;j--){
          if(arr[j]>temp){
            arr[j+1] = arr[j];
          }else{
            break;
          }
        }
        arr[j+1] = temp;
      }
      return arr;
    }
    int* ShellSort(int* arr,int size){
      int gap = size/3+1;
      while(gap>0){
        for(int i = gap;i<size;i+=gap){
          int temp = arr[i];
          int j = i-gap;
          for(;j>=0;j-=gap){
            if(arr[j]>temp){
              arr[j+gap] = arr[j];
            }else{
              break;
            }
          }
          arr[j+gap] = temp;
        }
        gap--;
      }
      return arr;
    }
    int * SelectSort(int*arr,int size){
      int begin = 0;
      int end = size-1;
      while(begin<end){
        int Maxpos = begin;
        int Minpos = begin;
        for(int i = begin;i<=end;i++){
          if(arr[Maxpos]<arr[i]){
            Maxpos = i;
          }
          if(arr[Minpos]>arr[i]){
            Minpos = i;
          }
        }
        Swap(arr+Maxpos,arr+end);
        if(Minpos==end)
          Minpos=Maxpos;
        Swap(arr+Minpos,arr+begin);
        --end;
        ++begin;
      }
      return arr;
    }
    int* HeapSort(int* arr,int size){
      CreatHeap(arr,size);
      for(int i=0;i<size-1;i++){
        Swap(arr+0,arr+size-1-i);
        AdjustDown(arr,size-1-i,0);
      }
      return arr;
    }
  private:
    void CreatHeap(int* arr,int size){
      for(int i = (size-2)/2;i>=0;i--){
        AdjustDown(arr,size,i);
      }
    }
    void AdjustDown(int* arr,int size,int root){//大堆
      assert(root<size);
      int parent = root;
      int child = parent*2+1;
      while(child<size){
        if(child+1<size){
          child = arr[child]>arr[child+1]?child:child+1;
        }
        if(arr[parent]>=arr[child])
          break;
        Swap(arr+parent,arr+child);
        parent = child;
        child = parent*2+1;
    }
    }
    void Swap(int*a,int*b){
      int temp = *b;
      *b = *a;
      *a = temp;
    }
    int* _arr ;
    int _size;
};




int main(){
  int arr[] = {2,4,6,3,7,9,5,8,10,1};
  int size  = sizeof(arr)/sizeof(arr[0]);
  Solution a(arr,size);
  //a.BubbleSort(arr,size);
  // a.InsertSort(arr,size);
  //a.ShellSort(arr,size);
  //a.SelectSort(arr,size);
  a.HeapSort(arr,size);
  for(int i = 0;i<size;i++){
    cout<<arr[i]<<' ';
  }
  cout<<endl;
  return 0;
}
