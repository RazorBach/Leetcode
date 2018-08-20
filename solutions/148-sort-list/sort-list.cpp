// Sort a linked list in O(n log n) time using constant space complexity.
//
// Example 1:
//
//
// Input: 4->2->1->3
// Output: 1->2->3->4
//
//
// Example 2:
//
//
// Input: -1->5->3->4->0
// Output: -1->0->3->4->5
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
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
private:
    ListNode* merge(ListNode* h1, ListNode* h2) {
        if(!h1) return h2;
        else if(!h2) return h1;
        ListNode* prev = new ListNode(0),*head = prev;
        while(h1 && h2) {
            if(h1->val < h2->val) {
                prev->next = h1;
                h1 = h1->next;
            }else{
                prev->next = h2;
                h2 = h2->next;
            }
            prev = prev->next;
            prev->next = nullptr;
        }
        if(h1) prev->next = h1;
        else prev->next = h2;
        return head->next;
    }
    ListNode* mergeSort(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* fast = head, *slow = head;
        while(fast&&fast->next&&fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;
        slow->next = nullptr;
        return merge(mergeSort(head), mergeSort(fast));
        
    }
    
};
