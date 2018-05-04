// Reverse a linked list from position m to n. Do it in one-pass.
//
// Note: 1 ≤ m ≤ n ≤ length of list.
//
// Example:
//
//
// Input: 1->2->3->4->5->NULL, m = 2, n = 4
// Output: 1->4->3->2->5->NULL
//
//


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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode **pp = &head,**pp2;
        for(int i = 1; i < m; i++)
            pp = &(*pp)->next;
        pp2 = &(*pp)->next;
        for(int i = 0; i < n - m; ++i){
            ListNode* tmp = *pp2;
            *pp2 = (*pp2)->next;
            tmp->next = *pp;
            *pp = tmp;
        }
        return head;
    }
};
