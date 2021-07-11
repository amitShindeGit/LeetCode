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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int length = inorder.size();
        return helper(inorder, preorder, 0, length-1, 0, length-1);
    }
    
TreeNode* helper(vector<int>& inorder, vector<int>& preorder, int inStart, int inEnd, int preStart, int preEnd){
      if(inStart > inEnd){
          return NULL;
      }     
    
        
      int rootVal = preorder[preStart];
      TreeNode * root = new TreeNode(rootVal);
    
      int rootIndex = inStart;
    
      for(; rootIndex<inEnd; rootIndex++){
          if(inorder[rootIndex] == rootVal){
              break;
          }
      }
    
     int leftTreeSize = rootIndex - inStart;
     int rightTreeSize = leftTreeSize+preStart+1; //adding 1 because first element is root in PreOrder, so we skip that first element by adding 1
    
     root->left = helper(inorder, preorder, inStart, rootIndex-1, preStart+1, leftTreeSize);
     root->right = helper(inorder, preorder, rootIndex+1, inEnd, rightTreeSize, preEnd);
    
     return root;
    }
};
