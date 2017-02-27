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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *headptr = new ListNode(0);
        ListNode *p = headptr;
        while(l1||l2||carry){
            int sum = (l1?l1->val:0) + (l2?l2->val:0) + carry;
            carry =  sum / 10;
            p->next = new ListNode(sum % 10);
            p = p->next;
            l1 = l1?l1->next:l1;
            l2 = l2?l2->next:l2;
        }
        return headptr->next;
    }
};
