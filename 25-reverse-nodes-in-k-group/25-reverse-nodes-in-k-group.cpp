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
    ListNode* reverseKGroup(ListNode* head, int k) {
     //tocheck if nodes in ll >=k or not
        ListNode *temp=head;
        for(int i=0;i<k;i++){
            if(temp==NULL){
                
                return head;
            }
            temp=temp->next;
        }
        
        ListNode *prev=NULL;
        ListNode *nex=NULL;
        ListNode *cur=head;
        //now reverse nodes only k times
        
        //earlier head was the first el of ll
        
        for(int i=0;i<k;i++){
            
            nex=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nex;
            
        }
        
        //after reversing k group head would be pointing to last node of group 
        // cur and nex are point to next node of the group ..recursive call it
        
        head->next= reverseKGroup(cur,k);
        return prev;
        
        
        
    }
};