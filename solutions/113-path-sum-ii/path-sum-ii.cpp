// Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
//
// Note: A leaf is a node with no children.
//
// Example:
//
// Given the below binary tree and sum = 22,
//
//
//       5
//      / \
//     4   8
//    /   / \
//   11  13  4
//  /  \    / \
// 7    2  5   1
//
//
// Return:
//
//
// [
//    [5,4,11,2],
//    [5,8,4,5]
// ]
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> tmp;
        vector<vector<int>> ret;
        find(root, sum, tmp,ret);
        return ret;
    }
private:
    void find(TreeNode* root,int sum, vector<int>& tmp, vector<vector<int>>& ret) {
        if(!root) return;
        tmp.push_back(root->val);
        if(!root->left && !root->right && root->val == sum)
            ret.push_back(tmp);
        find(root->left, sum - root->val, tmp, ret);
        find(root->right, sum - root->val, tmp, ret);
        tmp.pop_back();
    }
    
};
