// Given a binary tree, return the postorder traversal of its nodes' values.
//
// Example:
//
//
// Input: [1,null,2,3]
//    1
//     \
//      2
//     /
//    3
//
// Output: [3,2,1]
//
//
// Follow up: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> visit;
        TreeNode* cur = root, *prev = nullptr;
        vector<int> ret;
        while(cur || !visit.empty()) {
            if(cur) {
                visit.push(cur);
                cur = cur->left;
            }else {
                cur = visit.top();
                if(cur->right && cur->right != prev) {
                    cur = cur->right;
                }else{
                    ret.push_back(cur->val);
                    visit.pop();
                    prev = cur;
                    cur = nullptr;
                }
            }
        }
        return ret;
    }
};
