// Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
//
//
// For example:
// Given binary tree [3,9,20,null,null,15,7],
//
//     3
//    / \
//   9  20
//     /  \
//    15   7
//
//
//
// return its zigzag level order traversal as:
//
// [
//   [3],
//   [20,9],
//   [15,7]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int> > ret;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = 0;
        while(!q.empty()) {
            vector<int> vret;
            int count = q.size();
            for(int i = 0; i < count; ++i) {
                TreeNode* p = q.front();
                vret.push_back(p->val);
                q.pop();
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
            if(flag)
                reverse(vret.begin(), vret.end());
            flag ^= 1;
            ret.emplace_back(vret);
        }
        return ret;
    }
};
