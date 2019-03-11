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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return help(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
    TreeNode* help(vector<int>& pre,vector<int>& vin, int pbegin, int pend, int vbegin, int vend){
        if(pbegin > pend || vbegin > vend) return nullptr;
        int mid = pre[pbegin], i = vbegin;
        while(vin[i] != mid){ i++; }
        int len = i - vbegin;
        TreeNode *newnode = new TreeNode(mid);
        newnode->left = help(pre, vin, pbegin+1, pbegin+len, vbegin, i-1);
        newnode->right = help(pre, vin, pbegin+len+1, pend, i+1, vend);
        return newnode;
    }
};