#include<iostream>
using namespace std;

struct ListNode{
  int val;
  ListNode* next;
  void* operator new(size_t n){//重载自定义类型 new
    void*p = NULL;
    p = allocator<ListNode>().allocate(1);
    cout<<"memory pool allocate"<<endl;
    return p;
  }
  void operator delete(void* p){//重载自定义类型 delete
    allocator<ListNode>().deallocate((ListNode*)p,1);
    cout<<"memory pool deallocate"<<endl;
  }

};

class SList{
  friend class Solution;
  public:
  SList(int* data_arr=NULL,int arrSzie=0 )
    :_data_arr(data_arr)
     ,_arrSzie(arrSzie)
  {}
  ~SList(){
    while(_pre!=NULL){
      ListNode*self = _pre;
      _pre = _pre->next;
      delete self;

    }

  }
  ListNode*CreatAList(){
    for(int i=0;i<_arrSzie;i++){
      if(i==0){
        _frist = new ListNode;
        _frist->val = *(_data_arr+i);
        _pre = _frist;

      }else{
        ListNode* fresh = new ListNode;
        fresh->val = *(_data_arr+i);
        _frist->next = fresh;
        _frist = _frist->next;

      }

    }
    _frist->next = NULL;
    return _pre;

  }
  private:
  int* _data_arr;
  int _arrSzie;
  ListNode* _frist = NULL;
  ListNode* _pre = NULL;

};
class Solution {
  public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
      ListNode *fake = new ListNode;
      fake->next = pHead;
      fake->val = 0;
      ListNode *pre = fake,*check = pHead,*go = pHead;
      while(check!=NULL){
        while(go!=NULL&&check->val == go->val){
          go=go->next;
        }
        if(check->next==go){
          pre->next = check;
          pre = pre->next;
          go = check = pre->next;
        }else{
          check = go;
        }
      }
      pre->next = NULL;
      ListNode*back = fake->next;
      delete fake;
      return back;
    }
};


int main(){
  int arr[]={1,2,3,4,5,5,5,9,9,10};
  int arrSize = sizeof(arr)/sizeof(arr[0]);
  SList test(arr,arrSize);
  ListNode* head = test.CreatAList();
  Solution go;
  ListNode*result = go.deleteDuplication(head);
  while(result){
    cout<<result->val<<endl;
    result = result->next;
  }
  return 0;

}
