// Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
//
// Example:
//
// Input: 1->2->4, 1->3->4
// Output: 1->1->2->3->4->4
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ret = new ListNode(0), * head;
        head = ret;
        while(l1 || l2) {
            if(!l1){
                head->next = new ListNode(l2->val);
                l2 = l2->next;
                head = head->next;
            } else if(!l2) {
                head->next = new ListNode(l1->val);
                l1 = l1->next;
                head = head->next;
            } else {
                if(l1->val < l2->val) {
                    head->next = new ListNode(l1->val);
                    head = head->next;
                    l1 = l1->next;
                }else {
                    head->next = new ListNode(l2->val);
                    head = head->next;
                    l2 = l2->next;
                }
            }
            
        }
        return ret->next;
    }
};
