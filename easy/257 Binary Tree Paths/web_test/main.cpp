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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root == NULL) return res;
        stack<TreeNode*> s;
        stack<string> pathStack;
        s.push(root);
        pathStack.push(to_string(root->val));
        
        while (!s.empty()) {
            TreeNode * curNode = s.top(); s.pop();
            string tmpPath = pathStack.top(); pathStack.pop();
            
            if (curNode->left == NULL && curNode->right == NULL) {
                res.push_back(tmpPath); continue;
            }
            
            if (curNode->left != NULL) {
                s.push(curNode->left);
                pathStack.push(tmpPath + "->" + to_string(curNode->left->val));
            }
            
            if (curNode->right != NULL) {
                s.push(curNode->right);
                pathStack.push(tmpPath + "->" + to_string(curNode->right->val));
            }
        }
        
        return res;
    }
};


class Solution {
private:
    vector< vector<int> > paths;
    
public:
    
    string createString(vector<int> &vec) {
        string path_str;
        vector<int>::iterator it = vec.begin();
        path_str = std::to_string(*it);
        ++it;

        for ( ; it != vec.end(); ++it) {
            path_str += "->";
            path_str += to_string(*it);
        }
        return path_str;
    }
    
    void insertTreePaths(TreeNode* root, vector<int> &vals) {
            
        if (root == NULL) 
            return;
        
        vals.push_back(root->val);
        
        if (root->right == NULL && root->left == NULL){
            paths.push_back(vals);
        } else {
            insertTreePaths(root->left, vals);
            insertTreePaths(root->right, vals);
        }
        
        vals.pop_back();
        return;
    }
    

    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> vals;
        vector<string> str_paths;
        
        if (root == NULL)
            return vector<string> {};
        
        vals.push_back(root->val);
        if (root->right == NULL && root->left == NULL){
            paths.push_back(vals);
        } else {     
            insertTreePaths(root->left, vals);
            insertTreePaths(root->right, vals);
        }
       
        for (vector< vector<int> >::iterator it = paths.begin(); it != paths.end(); ++it) {
                string path_str = createString(*it);
                str_paths.push_back(path_str);
            }
        
        return str_paths; 
    }
};