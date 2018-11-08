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
    void flatten(TreeNode* root) 
    {
      while(root)
      {
          TreeNode* curr = root;
          if(root->left)
          {
              TreeNode* temp = curr->left;
              while(temp->right) temp = temp->right;
              temp->right = curr->right;
              curr->right = curr->left;
              curr->left = NULL;
               curr = curr->right;
          }
          root= root->right;
      }   
    }
  
};