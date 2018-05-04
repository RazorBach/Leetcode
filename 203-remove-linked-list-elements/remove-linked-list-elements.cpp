// Remove all elements from a linked list of integers that have value val.
//
// Example:
//
//
// Input:  1->2->6->3->4->5->6, val = 6
// Output: 1->2->3->4->5
//
// Credits:
// Special thanks to @mithmatt for adding this problem and creating all test cases.
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode** pp = &head;
        while(*pp) {
            if((*pp)->val == val) {
                *pp = (*pp)->next;
            }else{
                pp = &(*pp)->next;
            }
        }
        return head;
    }
};
