/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
private:
    bool path(TreeNode *root,TreeNode *target,vector<TreeNode *>& t_path){
        if(root == NULL) return false;
        if(root == target){
            t_path.push_back(root);
            return true;
        }
        bool l = path(root->left,target,t_path), r = path(root->right,target,t_path);
        if(l||r){
            t_path.push_back(root);
            return true;
        }
        return false;
    }
public:
    /*
     * @param root: The root of the binary tree.
     * @param A: A TreeNode
     * @param B: A TreeNode
     * @return: Return the LCA of the two nodes.
     */
    TreeNode * lowestCommonAncestor3(TreeNode * root, TreeNode * A, TreeNode * B) {
        if(root == NULL) return NULL;
        if(A == B) return A;
        // write your code here
        vector<TreeNode *> a_path,b_path;
        if(!path(root,A,a_path) || !path(root,B,b_path))
            return NULL;
        int i = a_path.size()-1,j = b_path.size()-1;
        while(i >= 0 && j >= 0){
            if(a_path[i] != b_path[j]){
                return a_path[i+1];
            }
            i--;
            j--;
        }
        return i >= 0 ? a_path[i+1] : b_path[j+1];
    }
};


typedef struct ResultType{
    bool is_a = false,is_b = false;
    TreeNode *lca = NULL;
    ResultType(TreeNode * lca = NULL, bool a = false, bool b = false){
        this->is_a = a;
        this->is_b = b;
        this->lca = lca;
    }
    bool haveres(){
        if(is_a && is_b)
            return true;
        return false;
    }
    bool haveinfo(){
        if(is_a || is_b)
            return true;
        return false;
    }
    void showinfo(string info = "info"){
        cout << info << endl;
        cout << is_a << " " << is_b << " ";
        if(lca == NULL)
            cout << "NULL" << endl;
        else
            cout << lca->val << endl;
    }
}ResT;

class Solution {
private:
    ResultType help(TreeNode *root, TreeNode *A, TreeNode *B){
        if(root == NULL) return ResT();
        if(root == A && root == B){
            return ResT(root,true,true);
        }
        ResultType lr = help(root->left,A,B);
        ResultType rr = help(root->right,A,B);
        if(root == A){
            if(lr.is_b || rr.is_b)
                return ResT(root,true,true);
            return ResT(root,true,false);
        }
        else if(root == B){
            if(lr.is_a || rr.is_a)
                return ResT(root,true,true);
            return ResT(root,false,true);
        }
        else if((lr.is_a && rr.is_b)||(lr.is_b && rr.is_a)){
            return ResT(root,true,true);
        }
        else if(lr.haveinfo())
            return lr;
        else if(rr.haveinfo())
            return rr;
        else
            return ResT();
    }
public:
    /*
     * @param root: The root of the binary tree.
     * @param A: A TreeNode
     * @param B: A TreeNode
     * @return: Return the LCA of the two nodes.
     */
    TreeNode * lowestCommonAncestor3(TreeNode * root, TreeNode * A, TreeNode * B) {
        ResT res = help(root,A,B);
        if(res.haveres())
            return res.lca;
        else
            return NULL;
    }
};