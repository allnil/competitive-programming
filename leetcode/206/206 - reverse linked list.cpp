class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* ans = nullptr;
        ListNode* node = nullptr;
        
        while (head != nullptr) {
            node = head;
            head = head->next;
            node->next = ans;
            ans = node;
        }
        
        return ans;
    }
};