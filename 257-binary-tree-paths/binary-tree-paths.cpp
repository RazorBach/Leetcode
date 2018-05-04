//
// Given a binary tree, return all root-to-leaf paths.
//
//
// For example, given the following binary tree:
//
//
//
//    1
//  /   \
// 2     3
//  \
//   5
//
//
//
// All root-to-leaf paths are:
// ["1->2->5", "1->3"]
//
//
// Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.


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
        vector<string> ret;
        string str = "";
        // ret.push_back(str);
        TreeNode* p = root;
        stack<TreeNode*> s;
        map<TreeNode*, string> map;
        while(!s.empty() || p) {
            while(p){
                s.push(p);
                str += "->" + std::to_string(p->val) ;
                map[p] = str;
                p = p->left;
            }
            p = s.top();
            s.pop();
            if(p->right)
                str = map[p];
            else if(!p->right && !p->left)
                ret.push_back(str.substr(2));
            p = p->right;
        }
        return ret;
    }
};
