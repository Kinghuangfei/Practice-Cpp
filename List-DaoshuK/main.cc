
class Solution {
  public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
      if(pListHead ==nullptr||k<=0)
        return nullptr;
      ListNode* p,*q;
      p=q=pListHead;
      for(int i = 1;i<k;i++){
        if(p->next!=nullptr)
          p=p->next;
        else
          return nullptr;

      }
      while(p->next!=nullptr){
        p=p->next;
        q=q->next;

      }
      return q;

    }

};
