// Given a binary tree
//
//
// struct TreeLinkNode {
//   TreeLinkNode *left;
//   TreeLinkNode *right;
//   TreeLinkNode *next;
// }
//
//
// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
//
// Initially, all next pointers are set to NULL.
//
// Note:
//
//
// 	You may only use constant extra space.
// 	Recursive approach is fine, implicit stack space does not count as extra space for this problem.
//
//
// Example:
//
// Given the following binary tree,
//
//
//      1
//    /  \
//   2    3
//  / \    \
// 4   5    7
//
//
// After calling your function, the tree should look like:
//
//
//      1 -> NULL
//    /  \
//   2 -> 3 -> NULL
//  / \    \
// 4-> 5 -> 7 -> NULL
//
//


/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        TreeLinkNode* pleft = root, *cur = root;
        while(pleft) {
            cur = pleft;
            TreeLinkNode* cfirst = nullptr,*cpre = nullptr;
            while(cur) {
                if(cur->left) {
                    if(cpre) 
                        cpre = cpre->next = cur->left;
                    else 
                        cpre = cfirst = cur->left;
                }
                if(cur->right) {
                    if(cpre) 
                        cpre = cpre->next = cur->right;
                    else 
                        cpre = cfirst = cur->right;
                }
                cur = cur->next;
            }
            pleft = cfirst;
        }
    }
};
