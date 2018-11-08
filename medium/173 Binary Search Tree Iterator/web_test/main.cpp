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
public:
    stack<TreeNode*> data;
    TreeNode* curr;
    
    BSTIterator(TreeNode *root) {
        curr = root;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (curr == NULL && data.empty() == true){
            return false;
        } else {
            return true;
        }
    }

    /** @return the next smallest number */
    int next() {
        
        while (curr != NULL){
            data.push(curr);
            curr = curr->left;
        }
        
        curr = data.top();
        data.pop();
        
        int temp = curr->val;
        curr = curr->right;
        
        return temp;
        
    }
};


class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        while (root) {
            st.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *node = st.top();
        st.pop();
        TreeNode *t = node->right;
        while (t) {
            st.push(t);
            t = t->left;
        }
        return node->val;
    }
    
private:
    stack<TreeNode*> st;
};
/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */