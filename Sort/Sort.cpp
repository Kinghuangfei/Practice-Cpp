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
    int* MergeSort(int*arr,int size){
      int* extra = new int[size];
      _MergeSort(arr,0,size,extra);
      delete[] extra;
      return arr;
    }
    int* MergeSort_Nor(int*arr,int size){
      int* extra = new int[size];
      for(int i = 1;i<size;i*=2){
        for(int j = 0;j<size;j+=2*i){
          int left = j;
          int mid = left+i;
          if(mid>=size)
            mid = size;
          int right = mid+i;
          if(right>size)
            right = size;
          Merge(arr,left,mid,right,extra);
        }
      }
      delete[] extra;
      return arr;
    }
    int* QuickSort(int*arr,int size){
      _QuickSort(arr,0,size-1);
      return arr;
    }
  private:
    void _QuickSort(int* arr,int left,int right){
      if(left>=right){
        return;
      }
      int flag = PickMid(arr,left,right);
      Swap(arr+flag,arr+right);
      int flag_index = Paration_hole(arr,left,right);
      _QuickSort(arr,left,flag_index-1);
      _QuickSort(arr,flag_index+1,right);
    }
    int Paration_hoare(int* arr,int left,int right){//hoare 
      int start = left;
      int end = right;
      while(start<end){
        while(start<end&&arr[start]<arr[right]){
          start++;
        }
        while(start<end&&arr[end]>=arr[right]){
          end--;
        }
        Swap(arr+start,arr+end);
      }
      Swap(arr+start,arr+right);//exchange flag to middle of array;
      return start;
    }
    int Paration_OSOG(int* arr,int left,int right){//One go One static
      int place = left;
      for(int i = place;i<right;i++){
        if(arr[i]<arr[right]){
          Swap(arr+place,arr+i);
          place++;
        }
      }
        Swap(arr+place,arr+right);
        return place;
    }
    int Paration_hole(int* arr,int left,int right){
      int start = left;
      int end  = right;
      int hole = arr[right];
      while(start<end){
        while(start<end&&arr[start]<=hole){
          start++;
        }
        arr[end] = arr[start];
        while(start<end&&arr[end]>=hole){
          end--;
        }
        arr[start] = arr[end];
      }
      arr[start] = hole;
      return start;
    }
    int PickMid(int*arr,int left,int right){
      int mid = left +(right-left)/2;
      if(arr[left]<arr[mid]){
        if(arr[mid]<arr[right]){
          return mid;
        }else 
          return arr[left]<arr[right]?right:left;
      }
      else if (arr[left]==arr[mid]){
        return right;
      }
      else{
        if(arr[left]<arr[right]){
          return left;
        }else 
          return arr[mid]<arr[right]?right:mid;
      }
    }
    void _MergeSort(int*arr,int start,int end,int* extra){
      if((end-start)<=1){
        return;
      }
      int mid = start+(end-start)/2;
      _MergeSort(arr,start,mid,extra);
      _MergeSort(arr,mid,end,extra);
      Merge(arr,start,mid,end,extra);
    }
    void Merge(int* arr,int start,int mid,int end,int* extra){
      int size =end-start;
      int left = start;
      int right = mid;
      int extra_inbox = 0;
      while(left<mid&&right<end){
        if(arr[left]<=arr[right]){
          extra[extra_inbox++]=arr[left++];
        }else{
          extra[extra_inbox++] = arr[right++];
        }
      }
      while(left<mid){
        extra[extra_inbox++]=arr[left++];
      }
      while(right<end){
        extra[extra_inbox++] = arr[right++];
      }
      for(int i = 0;i<size;i++){
        arr[start+i] = extra[i];
      }
    }
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
  int arr[] = {2,4,6,3,7,9,5,8,10,1,14,23,13,12,52};
  int size  = sizeof(arr)/sizeof(arr[0]);
  Solution a(arr,size);
  //a.BubbleSort(arr,size);
  // a.InsertSort(arr,size);
  //a.ShellSort(arr,size);
  //a.SelectSort(arr,size);
  //a.HeapSort(arr,size);
  //a.MergeSort(arr,size);
  //a.MergeSort_Nor(arr,size);
  a.QuickSort(arr,size);
  for(int i = 0;i<size;i++){
    cout<<arr[i]<<' ';
  }
  cout<<endl;
  return 0;
}
