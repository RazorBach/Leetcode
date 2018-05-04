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
        //遍历vector 时间复杂度为: N + 2N + ··· + KN = O(NK*K);
        // ListNode* head = nullptr;
        // for(auto node : lists){
        //     head = mergeTwo(head, node);
        // }
        // return head;
        
        //如果每次选2个进行merge 时间复杂度为 2N*K/2 + 4N*K/4 + ··· + (2^lgk*N)*K/2^lgk = O(lgk*KN);
        if(lists.empty()) return NULL;
        int len = lists.size();
        while(len > 1){
            for(int i = 0; i < len/2; ++i){
                lists[i] = mergeTwo(lists[i], lists[len - i - 1]);
            }
            len = (len + 1)/2;
        }
        return lists.front();
    }
private:
    ListNode* mergeTwo(ListNode* l1,ListNode* l2){
        ListNode dummy(INT_MIN);
        ListNode* prev = &dummy;
        while(l1 && l2){
            if(l1->val < l2->val){
                prev->next = l1;
                l1 = l1->next;
            }else{
                prev->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;
        }
        prev->next = l1 ? l1 : l2;
        return dummy.next;
    }
};
