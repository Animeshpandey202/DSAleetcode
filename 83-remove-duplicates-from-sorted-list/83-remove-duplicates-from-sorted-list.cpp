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
        
        if(head==NULL)return head;
        
        ListNode *itr=head;
        
        while(itr!=NULL && itr->next!=NULL){
            
            if(itr->val==itr->next->val){
                ListNode *node2delete=itr->next;
                itr->next=itr->next->next;
                delete node2delete;
            }
            else{
                
                itr=itr->next;
            }
            
        }
        return head;
        
    }
};