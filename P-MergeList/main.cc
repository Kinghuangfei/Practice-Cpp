/*
 * struct ListNode {
 *  int val;
 *    struct ListNode *next;
 *      ListNode(int x) :
 *            val(x), next(NULL) {
 *              }
 *              };*/
class Solution {
  public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
      ListNode* t1=pHead1,*t2=pHead2,*Head,*go;
      bool first=1;
      if(!t1)
        return t2;
      else if(!t2)
        return t1;
      while(t1&&t2){
        if(t1->val<=t2->val){
          if(first){
            Head = go = t1;
            first = 0;

          }else{
            go->next = t1;
            go = go->next;

          }
          t1 = t1->next;

        }else{
          if(first){
            Head = go = t2;
            first = 0;

          }else{
            go->next = t2;
            go = go->next;

          }
          t2 = t2->next;

        }

      }
      if(t1==NULL)
        go->next = t2;
      else if(t2==NULL)
        go->next = t1;
      else
        go->next = NULL;
      return Head;

    }

};
*            }
* }
