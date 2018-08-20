// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
//
// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
//
// Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]
//
//  
//
// Example 1:
//
//
// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
// Output: 3
// Explanation: The LCA of nodes 5 and 1 is 3.
//
//
// Example 2:
//
//
// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
// Output: 5
// Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
//
//
//  
//
// Note:
//
//
// 	All of the nodes' values will be unique.
// 	p and q are different and both values will exist in the binary tree.
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        deque<TreeNode*> v1, v2;
        //要采用后序遍历保留父节点信息
        TreeNode* cur = root, *prev = nullptr;
        while(cur || !v1.empty()) {
            if(cur) {
                v1.push_back(cur);
                cur = cur->left;
            }else{
                cur = v1.back();
                if(cur->right && cur->right != prev) {
                    cur = cur->right;
                }else {
                    if(cur == p || cur == q) {
                        if(v2.empty())
                            v2 = v1;
                        else
                            break;
                    }
                    v1.pop_back();
                    prev = cur;
                    cur = nullptr;
                }
            }
        }
        TreeNode* ret = nullptr;
        for(int i = 0; i < v1.size() && i < v2.size(); ++i) {
            if(v1[i] == v2[i])
                ret = v1[i];
            else
                break;
        }
        return ret;
    }
};
