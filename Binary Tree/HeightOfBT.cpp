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
    int maxDepth(TreeNode* root) {
        struct TreeNode *t = root;
        if(t == NULL){
            return 0; //-1 if we wish to calculate height on the basis of edge
        }else{
            
            int lheight = maxDepth(t->left);
            int rheight = maxDepth(t->right);
            
            if(lheight > rheight){
                return lheight + 1;
            }else{
                return rheight + 1;
            
            }
        }
    }
};