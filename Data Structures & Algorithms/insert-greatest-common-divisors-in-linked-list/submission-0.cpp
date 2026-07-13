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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *p = head;
        ListNode *q = head->next;
        if(!q) return head;
        while( q != nullptr){
            int g = gcd(p->val,q->val);
            ListNode * temp = new ListNode(g,q);
            p->next = temp;
            p = q;
            q = q->next;
        }
        return head;
    }
};