// Given two binary trees, write a function to check if they are the same or not.
//
// Two binary trees are considered the same if they are structurally identical and the nodes have the same value.
//
// Example 1:
//
//
// Input:     1         1
//           / \       / \
//          2   3     2   3
//
//         [1,2,3],   [1,2,3]
//
// Output: true
//
//
// Example 2:
//
//
// Input:     1         1
//           /           \
//          2             2
//
//         [1,2],     [1,null,2]
//
// Output: false
//
//
// Example 3:
//
//
// Input:     1         1
//           / \       / \
//          2   1     1   2
//
//         [1,2,1],   [1,1,2]
//
// Output: false
//
//


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> sp,sq;
        sp.push(p); sq.push(q);
        while(!sp.empty()){
            TreeNode* tp = sp.top(); sp.pop();
            TreeNode* tq = sq.top(); sq.pop();
            if(!tp && !tq)
                continue;
            if(!tp || !tq || tp->val != tq->val)
                return false;
            sp.push(tp->left);
            sq.push(tq->left);
            sp.push(tp->right);
            sq.push(tq->right);
        }
        return true;
    }
};
