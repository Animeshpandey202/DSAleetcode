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
    

    
    bool isPalindrome(ListNode* head) {
          // time=O(n/2 +n/2 +n/2)  middle reverse and comparison
        
        if(head==NULL || head->next==NULL)return true;
        
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            
            slow=slow->next;
            fast=fast->next->next;
        
        }
        
        slow->next=reverse(slow->next);
        slow=slow->next;
        ListNode *dummy=head;
        
        while(slow!=NULL){
            if(dummy->val!=slow->val)return false;
            else{
                dummy=dummy->next;
                slow=slow->next;
                
            }
        }
        return true;
        
    }
    
    ListNode *reverse(ListNode *head){
        //reverse by iteration
        
        ListNode* prev=NULL;
        ListNode* next=NULL;
        
        while(head!=NULL){
        next=head->next;
        head->next=prev;
        prev=head;
        head=next;
        }
        return prev;
        
    }
    
    
    //reverse by rrecursion
    //     ListNode* reverse(ListNode *head){
        
//          if(head->next==NULL){
//             return head;
//         }
//         ListNode *newhead=reverse(head->next);
        
       
//         head->next->next=head;
//         head->next=NULL;
        
//         return newhead;
        
        
        
//     }
    
    
};