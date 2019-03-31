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
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
      ListNode* slow = pHead;
      ListNode* fast = pHead;
      while(fast!=NULL){
        do{
          fast = fast->next;
          if(fast==NULL){
            return NULL;
          }
          slow = slow->next;
          fast = fast->next;
          if(fast==NULL){
            return NULL;
          }
        }while(fast!=slow);//确定是否带环；
        ListNode* go1 = slow;
        ListNode* start = pHead;
        while(go1!=start){
          go1 =go1->next;
          start = start->next;
        }
        return start;//确定入口位置：一个指针从快慢指针相交点开始，另一个从表头开始，两者相交点即为环的入口位置；
      }
      return NULL;
    }
  };

int main(){
  int arr[]={1,2,3,4,5,6,7,8,9,10};
  int arrSize = sizeof(arr)/sizeof(arr[0]);
  SList test(arr,arrSize);
  ListNode* head = test.CreatAList();
  Solution go;
  ListNode* result = go.EntryNodeOfLoop(head);
  if(result==NULL){
    cout<<"不是带环节点"<<endl;
  }else{
    cout<<"环的入口节点结点val为:"<<endl;
  }
  return 0;
}
