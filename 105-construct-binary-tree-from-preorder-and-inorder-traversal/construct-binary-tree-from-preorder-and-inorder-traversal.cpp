// Given preorder and inorder traversal of a tree, construct the binary tree.
//
// Note:
// You may assume that duplicates do not exist in the tree.
//
// For example, given
//
//
// preorder = [3,9,20,15,7]
// inorder = [9,3,15,20,7]
//
// Return the following binary tree:
//
//
//     3
//    / \
//   9  20
//     /  \
//    15   7
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i = 0, j = 0;
        TreeNode* root = new TreeNode(INT_MIN);
        TreeNode* pp = nullptr, *ptr = root;
        stack<TreeNode*> sn; sn.push(root);
        while(i < preorder.size()) {
            if(sn.top()->val == inorder[j]){
                pp = sn.top();
                sn.pop();
                j++;
            }else if(pp){
                ptr = new TreeNode(preorder[i++]);
                pp->right = ptr;
                pp = nullptr;
                sn.push(ptr);
            }else{
                ptr = new TreeNode(preorder[i++]);
                sn.top()->left = ptr;
                sn.push(ptr);
            }
        }
        return root->left;
    }
};
