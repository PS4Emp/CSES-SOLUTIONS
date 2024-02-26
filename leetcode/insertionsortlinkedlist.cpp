
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        
        ListNode* dummy = new ListNode(-1); 
        dummy->next = head;
        
        ListNode* curr = head; 
        ListNode* prev = dummy; 
        
        while (curr) {
            if (curr->next && curr->next->val < curr->val) {
                
                
                while (prev->next && prev->next->val < curr->next->val) {
                    prev = prev->next;
                }
                
                ListNode* temp = curr->next; 
                curr->next = curr->next->next;
                temp->next = prev->next;
                prev->next = temp;
                
                prev = dummy; 
            } else {
                
                curr = curr->next;
            }
        }
        
        return dummy->next; 
    }
};