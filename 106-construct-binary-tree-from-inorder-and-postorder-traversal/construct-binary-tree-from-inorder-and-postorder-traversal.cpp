// Given inorder and postorder traversal of a tree, construct the binary tree.
//
// Note:
// You may assume that duplicates do not exist in the tree.
//
// For example, given
//
//
// inorder = [9,3,15,20,7]
// postorder = [9,15,7,20,3]
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
    typedef vector<int>::iterator iter;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }
private:
    TreeNode* build(iter ibegin, iter iend, iter pbegin, iter pend) {
        if(ibegin >= iend) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(*(pend - 1));
        int i = 0;
        for(; ibegin + i < iend; ++i) {
            if(*(ibegin + i) == *(pend - 1)) {
                break;
            }
        }
        root->left = build(ibegin, ibegin + i, pbegin, pbegin + i);
        root->right = build(ibegin + i + 1, iend, pbegin + i, pend - 1);
        return root;
    }
};
