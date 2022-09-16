/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
           //optimal approach time=O(m+n) space=O(1)
        if(headA==NULL || headB==NULL )return NULL;
        
        ListNode *a=headA;
        ListNode *b=headB;
        
        while(a!=b){
            
            if(a==NULL){
                a=headB;
            }
            else{
                a=a->next;
            }
            
            if(b==NULL){
                b=headA;
            }
            else{
                b=b->next;
            }
            
            
        }
      
        return a;
        
	}
};


  ///brute=O(m*n) space=O(1)
//          if(headA ==NULL || headB==NULL)return NULL;
        
//         while(headA!=NULL){
            
//             ListNode *temp=headB;
            
//             while(temp!=NULL){
                
//                 if(temp==headA){
//                     return temp;
//                 }
//                 else{
//                     temp=temp->next;
//                 }
                
//             }
//             headA=headA->next;
            
      
            
//         }
        
//               return NULL;





