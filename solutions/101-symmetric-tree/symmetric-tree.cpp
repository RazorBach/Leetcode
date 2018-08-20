// Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
//
//
// For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
//
//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
//
//
//
// But the following [1,2,2,null,3,null,3]  is not:
//
//     1
//    / \
//   2   2
//    \   \
//    3    3
//
//
//
//
// Note:
// Bonus points if you could solve it both recursively and iteratively.
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
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        stack<TreeNode*> s;
        TreeNode* p = root->left, *q = root->right;
        s.push(p);
        s.push(q);
        while(!s.empty()){
            q = s.top(); s.pop();
            p = s.top(); s.pop();
            if(!p && !q) continue;
            if(!p || !q || p->val != q->val) return false;
            s.push(p->left);
            s.push(q->right);
            s.push(p->right);
            s.push(q->left);
        }
        return true;
        
        // if(!root) return true;
        // return isSame(root->left, root->right);
    }
private:
    bool isSame(TreeNode* p,TreeNode* q){
        if(!p && !q) return true;
        if(!p || !q) return false;
        return p->val == q->val && isSame(p->left, q->right) && isSame(p->right, q->left);
    }
};
