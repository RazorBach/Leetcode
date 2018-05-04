//
// A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
//
//
//
// Return a deep copy of the list.
//


/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode* cur = head;
        //copy a new list
        while(cur) {
            RandomListNode* newnode = new RandomListNode(cur->label);
            newnode->next = cur->next;
            cur->next = newnode;
            cur = newnode->next;
        }
        //copy random to new list
        cur = head;
        while(cur) {
            if(cur->random){
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        //restore old new and new list
        cur = head;
        RandomListNode* prev = new RandomListNode(INT_MIN),*newhead = prev;
        while(cur) {
            prev->next = cur->next;
            prev = prev->next;
            cur->next = prev->next;
            cur = cur->next;
        }
        return newhead->next;
    }
};
