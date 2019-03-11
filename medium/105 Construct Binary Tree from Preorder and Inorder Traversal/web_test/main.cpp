class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0){
            return nullptr;
        }
        
        stack<TreeNode*> s;
        TreeNode* p;
        TreeNode* root = new TreeNode(preorder[0]);
        int j=0;
        s.push(root);
        
        for(int i=1;i<preorder.size();i++){
            if(s.top()->val!=inorder[j] && s.top()->left==nullptr){
                TreeNode* node = new TreeNode(preorder[i]);
                s.top()->left=node;
                s.push(node);
            }else{
                while(s.empty()==false && s.top()->val == inorder[j]){
                    p=s.top();
                    s.pop();
                    j++;
                }
                p->right=new TreeNode(preorder[i]);
                s.push(p->right);
            }
        }
        return root;
    }
};