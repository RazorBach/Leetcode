//
// Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
//
//
//
// Note: Do not modify the linked list.
//
//
// Follow up:
// Can you solve it without using extra space?
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
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return nullptr;
	    ListNode* flag = head, *run = head->next;
        int move, steps = 1;
        while(run) {
            //run pointer moves 1,2,4····2^n steps
            for(move = 1; run && run != flag && move < steps; ++move) {
                run = run->next;
            }
            if(!run || run == flag)
                break;
            else{
                flag = run;
                run = run->next;
                steps *= 2;
            }
        }
        //no circle,simply return nullptr
        if(!run) return nullptr;
        //move is the length of circle,now we find the start point
        flag = head, run = head;
        for(int i = 0; i < move; ++i) {
            run = run->next;
        }
        while(flag != run){
            flag = flag->next;
            run = run->next;
        }
        return flag;
    }
};
