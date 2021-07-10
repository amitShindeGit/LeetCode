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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int length = inorder.size();
        return helper(inorder, postorder, 0, length-1, 0, length-1);
    }
    
    TreeNode* helper(vector<int>& In, vector<int>& Po, int InStart, int InEnd, int PoStart, int PoEnd){
        if(InStart > InEnd){
            return NULL; //Base Condition
        }
        
        int rootVal = Po[PoEnd];
        TreeNode *root = new TreeNode(rootVal);
        
        int rootIndex = InStart;
        for(; rootIndex < InEnd; rootIndex++){
            if(In[rootIndex] == rootVal){
                break;
            }
        }
        
        int leftTreeSize = rootIndex - InStart;
        int rightTreeSize = InEnd - rootIndex;
        
        root->left = helper(In, Po, InStart, rootIndex-1, PoStart, PoStart + leftTreeSize - 1);
        root->right = helper(In, Po, rootIndex + 1, InEnd, PoEnd - rightTreeSize, PoEnd - 1);
        return root;
        
    }
};