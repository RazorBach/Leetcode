// Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
//
// You should preserve the original relative order of the nodes in each of the two partitions.
//
// Example:
//
//
// Input: head = 1->4->3->2->5->2, x = 3
// Output: 1->2->2->4->3->5
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
    ListNode* partition(ListNode* head, int x) {
        ListNode **ppf = &head, **pps = &head;
        while(*pps != nullptr) {
            if((*pps)->val >= x) {
                pps = &(*pps)->next;
            }else if(pps == ppf) {
                pps = &(*pps)->next;
                ppf = &(*ppf)->next;
            }else{
                ListNode *tmp = *pps;
                *pps = (*pps)->next;
                tmp->next = *ppf;
                *ppf = tmp;
                ppf = &(*ppf)->next;
            }
        }
        return head;
    }
};
