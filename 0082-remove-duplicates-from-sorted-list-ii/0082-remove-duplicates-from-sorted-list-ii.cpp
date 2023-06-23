/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy= new ListNode(-1);
        dummy->next=head;
    if(!head)return head;
        ListNode *cur=head;
        ListNode* prev=dummy;
        
        while(cur!=NULL){
            bool isDuplicate=false;
         while( cur->next!=NULL && cur->val== cur->next->val){ 
            cur=cur->next; 
             isDuplicate=true;
        }
          if(isDuplicate){
              prev->next=cur->next;
              cur=cur->next;
          }else{
               prev=cur;
              cur=cur->next;
          }    
            
        }
        return dummy->next;
       
    }
};