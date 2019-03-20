// Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
//
// Example:
//
//
// Input: [1,2,3,null,5,null,4]
// Output: [1, 3, 4]
// Explanation:
//
//    1            <---
//  /   \
// 2     3         <---
//  \     \
//   5     4       <---
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        int level = -1;
        bfs(root, ret, level, 0);
        return ret;
    }
private:
    void bfs(TreeNode* root,vector<int>& ret,int& level,int now) {
        if(!root) return;
        if(now > level){
            ret.push_back(root->val);
            level++;
        }
        if(root->right) bfs(root->right, ret, level, now + 1);
        if(root->left) bfs(root->left, ret, level, now + 1);
    }
};
