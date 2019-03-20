// Two elements of a binary search tree (BST) are swapped by mistake.
//
// Recover the tree without changing its structure.
//
// Example 1:
//
//
// Input: [1,3,null,null,2]
//
//    1
//   /
//  3
//   \
//    2
//
// Output: [3,1,null,null,2]
//
//    3
//   /
//  1
//   \
//    2
//
//
// Example 2:
//
//
// Input: [3,1,4,null,null,2]
//
//   3
//  / \
// 1   4
//    /
//   2
//
// Output: [2,1,4,null,null,3]
//
//   2
//  / \
// 1   4
//    /
//   3
//
//
// Follow up:
//
//
// 	A solution using O(n) space is pretty straight forward.
// 	Could you devise a constant space solution?
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
    void recoverTree(TreeNode* root) {
        TreeNode* cur = root, *prev = nullptr, *sec = nullptr;
        bool swaped = false;
        stack<TreeNode*> s;
        while(cur || !s.empty()){
            while(cur){
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            s.pop();
            if(!prev || cur->val > prev->val){
                if(sec){
                    swap(prev->val, sec->val);
                    swaped = true;
                    break;
                }else{
                    prev = cur;
                }
            }else if(cur->val <= prev->val){
                sec = cur;
            }
            cur = cur->right;
        }
        if(!swaped)
            swap(prev->val, sec->val);
            
    }
};
