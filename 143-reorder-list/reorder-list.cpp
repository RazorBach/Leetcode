// Given a singly linked list L: L0→L1→…→Ln-1→Ln,
// reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
//
// You may not modify the values in the list's nodes, only nodes itself may be changed.
//
// Example 1:
//
//
// Given 1->2->3->4, reorder it to 1->4->2->3.
//
// Example 2:
//
//
// Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
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
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode *slow = head, *fast = head;
        while(fast && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // reverse the second half
        ListNode* l2 = slow->next, *pre = nullptr;
        slow->next = nullptr;
        while(l2){
            ListNode *next = l2->next;
            l2->next = pre;
            pre = l2;
            l2 = next;
        }
        
        //pre is the head of l2
        ListNode *next = head,*next2 = pre;
        while(pre){
            next = next->next;
            next2 = next2->next;
            head->next = pre;
            pre->next = next;
            
            head = next;
            pre = next2;
        }
    }
};
