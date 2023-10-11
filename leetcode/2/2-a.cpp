class Solution {
     ListNode* sum(ListNode* l1, ListNode* l2, int carry){
        if(l1 == nullptr && l2 == nullptr && carry == 0){
            return nullptr;
        }

        int sumVal = carry;
        if(l1 != nullptr) {
            sumVal += l1->val;
            l1 = l1->next;
        }
        if(l2 != nullptr) {
            sumVal += l2->val;
            l2 = l2->next;
        }

        ListNode* sumNode = new ListNode(sumVal % 10);
        carry = sumVal / 10;
        sumNode->next = sum(l1, l2, carry);
        return sumNode;
     }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       return sum(l1, l2, 0);
    }
};