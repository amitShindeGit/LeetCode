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
#include <queue>

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode *> q;
        vector<int> vt1;
        vector<vector<int>> vtvt;
        
        if(root != NULL){
          vt1.push_back(root->val);
           vtvt.push_back(vt1);
           q.push(root);
        }else{
            return vtvt;
        }
        
        
        while(!q.empty()){
            vector<int> vt ;
            int size = q.size();
            

            for(int i=0; i<size ; i++){
             struct TreeNode *p = q.front();
             q.pop();

             if(p != NULL && ( p->left != NULL || p->right != NULL) ){

            
              if(p->left != NULL){
                vt.push_back(p->left->val);
                q.push(p->left);
               }
            
              if(p->right != NULL){
                vt.push_back(p->right->val);
                q.push(p->right);
               }
            
             }
               
            } 
            
            if(vt.size() > 0){
              vtvt.push_back(vt);

            }     
        }
        
        
        return vtvt;
        
    }
};