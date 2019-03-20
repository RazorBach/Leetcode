// Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.
//
// Example:
//
//
// Input: 3
// Output:
// [
//   [1,null,3,2],
//   [3,2,null,1],
//   [3,1,null,null,2],
//   [2,1,3],
//   [1,null,2,null,3]
// ]
// Explanation:
// The above output corresponds to the 5 unique BST's shown below:
//
//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3
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
    vector<TreeNode*> generateTrees(int n) {
        if(!n) return {};
        vector<vector<vector<TreeNode*>>> vmap(n + 1, vector<vector<TreeNode*>>(n + 1,{nullptr}));
        return _gen(1, n, vmap);
    }
private:
    vector<TreeNode*> _gen(int a, int n, vector<vector<vector<TreeNode*>>> & vmap){
        //generate nodes(start from a, ends in n)
        vector<TreeNode*> ret;
        if(a > n) {
            ret.push_back(nullptr);
            return ret;
        }
        if(vmap[a][n][0])
            return vmap[a][n];
        for(int i = a; i <= n; ++i){
            vector<TreeNode*> leftSub = _gen(a, i - 1, vmap);
            vector<TreeNode*> rightSub = _gen(i + 1, n, vmap);
            
            for(TreeNode *left : leftSub){
                for(TreeNode *right : rightSub){
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    ret.push_back(root);
                }
            }
        }
        vmap[a][n] = ret;
        return ret;
    } 
};
