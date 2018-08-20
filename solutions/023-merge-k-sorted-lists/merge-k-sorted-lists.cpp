// Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
//
// Example:
//
//
// Input:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// Output: 1->1->2->3->4->4->5->6
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        if(!len) return nullptr;
        while(len > 1) {
            for(int  i = 0; i < len / 2; ++i) {
                lists[i] = mergeTwo(lists[i], lists[len - 1 - i]);
            }
            len = (len + 1) / 2;
        }
        return lists[0];
    }
private:
    ListNode* mergeTwo(ListNode* l1, ListNode* l2) {
        ListNode* ret = new ListNode(0), *head;
        head = ret;
        while(l1 && l2) {
            if(l1->val < l2->val) {
                ret->next = new ListNode(l1->val);
                l1 = l1->next;
                ret = ret->next;
            }else {
                ret->next = new ListNode(l2->val);
                l2 = l2->next;
                ret = ret->next;
            }
        }
        if(!l1) ret->next = l2;
        if(!l2) ret->next = l1;
        return head->next;
    }
};
