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
        vector<int> ret;
        stack<TreeNode*> toVisit;
        TreeNode* cur = root,*pre = nullptr;
        while(cur || !toVisit.empty()) {
            if(cur) {
                toVisit.push(cur);
                cur = cur->left;
            }else{
                cur = toVisit.top();
                if(cur->right && cur->right != pre) {
                    cur = cur->right;
                }else{
                    ret.push_back(cur->val);
                    toVisit.pop();
                    pre = cur;
                    cur = nullptr;
                }
            }
        }
        return ret;
    }
};
