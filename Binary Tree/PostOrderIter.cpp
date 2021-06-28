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
    vector<int> postorderTraversal(TreeNode* root) {
        
        stack<TreeNode *> st;
        vector<int> vt;
        struct TreeNode *t = root;
        
        while(!st.empty() || t != NULL){
            if(t != NULL){
                st.push(t);
                t = t->left;
            }else{
                struct TreeNode *temp = st.top()->right;
                
                if(temp == NULL){
                    temp = st.top();
                    vt.push_back(temp->val);
                    st.pop();
                    
                    while(!st.empty() && temp == st.top()->right){
                        temp = st.top();
                        vt.push_back(temp->val);
                        st.pop();
                    }
                }else{
                    t = temp;
                }
            }
            
        }
        
        return vt;
            
        } 
};