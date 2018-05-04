//
// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
//
//
//
// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”
//
//
//
//         _______3______
//        /              \
//     ___5__          ___1__
//    /      \        /      \
//    6      _2       0       8
//          /  \
//          7   4
//
//
//
// For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.


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
