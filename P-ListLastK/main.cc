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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
      ListNode* end = pListHead,*go = pListHead;
      if(end==NULL||k==0)
        return NULL;
      for(size_t i = 0;i<k;i++){
        end = end->next;
        if((!end)&&(i!=k-1))
          return NULL;

      }
      while(end!=NULL){
        end = end->next;
        go = go->next;

      }
      return go;

    }

};
