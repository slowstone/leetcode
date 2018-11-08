/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<int> tmp;
    void inorder(TreeNode *root){
        if(root == NULL) return;
        inorder(root->right);
        tmp.push(root->val);
        inorder(root->left);
    }
public:
    BSTIterator(TreeNode *root) {
        inorder(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !tmp.empty();
    }

    /** @return the next smallest number */
    int next() {
        int res = tmp.top();
        tmp.pop();
        return res;
    }
};