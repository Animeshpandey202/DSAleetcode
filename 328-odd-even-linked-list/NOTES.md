if(!head || !head->next || !head->next->next) return head;
​
ListNode *odd = head, *even = head->next, *even_head = even;
while(odd->next && even->next) {
odd->next = odd->next->next;
even->next = even->next->next;
odd = odd->next;
even = even->next;
}
odd->next = even_head;
return head;Time Complexity: O(n)
Space Complexity: O(1)
​
class Solution {
public:
ListNode* oddEvenList(ListNode* head) {
if(!head || !head->next || !head->next->next) return head;
​
ListNode *odd = head, *even = head->next, *even_head = head->next;
while(odd->next && even->next) {
odd->next = odd->next->next;
even->next = even->next->next;
odd = odd->next;
even = even->next;
}
odd->next = even_head;
return head;
}
};