struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head; // Base case: empty list or single node
        }
        
        // Find the middle of the list using slow and fast pointers
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* mid = slow->next; // Middle node
        slow->next = NULL; // Split the list into two halves
        
        // Recursively sort the two halves
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        
        // Merge the sorted halves
        return merge(left, right);
    }

private:
    // Merge two sorted lists
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        
        tail->next = (l1 != NULL) ? l1 : l2; // Append remaining nodes
        return dummy.next;
    }
};