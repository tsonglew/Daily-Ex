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
        ListNode head(0);
        ListNode *headptr = &head;
        int flag = 0;
        int sum;
        while(l1||l2||flag){
            sum = (l1?l1->val:0) + (l2?l2->val:0) + flag;
            flag = sum / 10;
            headptr->next = new ListNode(sum%10);
            headptr = headptr->next;
            l1 = l1? l1->next: l1;
            l2 = l2? l2->next: l2;
        }
        return headptr->next;
    }
};
