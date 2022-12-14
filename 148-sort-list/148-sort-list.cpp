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
        ListNode* findmid(ListNode *head){
        
        ListNode *slow=head;
        ListNode *fast=head;
        ListNode *prev=NULL;
        while(fast!=NULL && fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
            
        }
        return prev;
        
    }
    
    
     ListNode *merge(ListNode *left,ListNode* right){
        
        if(left==NULL)return right;
        if(right==NULL)return left;
        
        
        ListNode *ans=new ListNode(-1);
        ListNode *temp=ans;
        
        while(left!=NULL && right!=NULL){
            
            if(left->val<=right->val){
                temp->next=left;
                temp=left;
                left=left->next;
            }
            else{
                temp->next=right;
                temp=right;
                right=right->next;
            }
            
            
        }
        
        if(left!=NULL){
            temp->next=left;
            
        }
         if(right!=NULL){
            temp->next=right;
            
        }
        
        return ans->next;
        
        
        
    }
    
public:
    //time=O(NlogN)  space=log(n)
      
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        
        
        ListNode *mid=findmid(head);
        
        ListNode *left=head;
        
        ListNode *right=mid->next;
        mid->next=NULL;
        
        left=sortList(left);
        right=sortList(right);
        
        ListNode *result=merge(left,right);
        return result;

        
    }
};