/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <stack>

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode *> st;
        vector<int> vt;
        
        struct TreeNode *t = root;
        
        while(!st.empty() || t != NULL){
            
            if(t!= NULL){
                 st.push(t);
                 t = t->left;                
            }else{
                t = st.top();
                st.pop();
                vt.push_back(t->val);
                t = t->right;
            }
        }
        
        return vt;
        
    }
};