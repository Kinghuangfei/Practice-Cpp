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
    ListNode* ReverseList(ListNode* pHead) {
      if(!pHead)
        return NULL;
      ListNode* Nex=pHead->next,*go = pHead,*pre=NULL;
      while(Nex){
        go->next = pre;
        pre = go;
        go = Nex;
        Nex = Nex->next;

      }
      go->next = pre;
      return go;

    }

};
