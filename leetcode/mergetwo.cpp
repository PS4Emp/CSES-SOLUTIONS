class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(); // Dummy node to simplify insertion
        ListNode* current = dummy; // Pointer to track the current position in the merged list
        
        while (list1 && list2) {
            if (list1->val < list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }
        
        // Append remaining nodes from list1 or list2
        if (list1) {
            current->next = list1;
        } else {
            current->next = list2;
        }
        
        return dummy->next; // Return the head of the merged list
    }
};