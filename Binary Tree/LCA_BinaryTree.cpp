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
        if(root == NULL){
            return NULL;
        }
        
        if(root->val == p->val || root->val == q->val){  //if root is itself p or q
            return root;
        }
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p ,q);
        
        if(left && right ){  //if both exists then only return root
            return root;
        }else if(left){
            return left;
        }else if(right){
            return right;
        }else{
            return NULL;   //if any of both doesn't exists, then we return null
         }
    }
};