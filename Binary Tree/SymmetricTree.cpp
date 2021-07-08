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
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        
       return isSymmetrical(root->left , root->right);
    }
    
    public: bool isSymmetrical(TreeNode* left, TreeNode* right ){
        if(left == NULL || right == NULL){
            return left == right;
        }
        
        if(left->val != right->val){
            return false;
        }
        
        return isSymmetrical(left->left , right->right) && isSymmetrical(left->right, right->left);
    }
};