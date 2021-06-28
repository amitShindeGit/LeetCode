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
    vector<int> preorderTraversal(TreeNode* root) {
       stack<TreeNode *> st;
       vector<int> vt;
        struct TreeNode *t = root;
        
        while(t != NULL || !st.empty()){
            if(t != NULL){
                vt.push_back(t->val);
                st.push(t);
                t = t->left;
            }else{
                t = st.top();
                st.pop();
                t = t->right;
            }
        }
        
        return vt;
    }
};