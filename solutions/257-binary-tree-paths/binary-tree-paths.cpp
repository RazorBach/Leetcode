// Given a binary tree, return all root-to-leaf paths.
//
// Note: A leaf is a node with no children.
//
// Example:
//
//
// Input:
//
//    1
//  /   \
// 2     3
//  \
//   5
//
// Output: ["1->2->5", "1->3"]
//
// Explanation: All root-to-leaf paths are: 1->2->5, 1->3
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string s;
        helper(root, s, res);
        return res;
    }
private:
    void helper(TreeNode* cur, string str, vector<string>& res) {
        if(!cur)
            return;
        str += "->" + std::to_string(cur->val);
        helper(cur->left, str, res);
        helper(cur->right, str, res);
        if(!cur->left && !cur->right)
            res.emplace_back(str.substr(2));
    }
};
