/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNodeAdd{
    TreeNode* ori;
    TreeNodeAdd* ancestor;
    TreeNodeAdd(TreeNode* x,TreeNodeAdd* y): ori(x), ancestor(y){}
};
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        queue<TreeNodeAdd*> treequeue;
        queue<int> heighqueue;
        TreeNodeAdd* tmp = new TreeNodeAdd(root,NULL);
        treequeue.push(tmp);
        heighqueue.push(0);
        int pheigh = 0;
        int qheigh = 0;
        TreeNodeAdd* ptmp = NULL;
        TreeNodeAdd* qtmp = NULL;
        while(!treequeue.empty()){
            TreeNodeAdd* tmp = treequeue.front();
            treequeue.pop();
            int heightmp = heighqueue.front();
            heighqueue.pop();
            if(tmp == NULL)
                continue;
            if(tmp->ori == p){
                pheigh = heightmp;
                ptmp = tmp;
            }
            if(tmp->ori == q){
                qheigh = heightmp;
                qtmp = tmp;
            }
            if(pheigh && qheigh)
                break;
            TreeNodeAdd* ltmp = new TreeNodeAdd(tmp->ori->left,tmp);
            TreeNodeAdd* rtmp = new TreeNodeAdd(tmp->ori->right,tmp);
            treequeue.push(ltmp);
            heighqueue.push(heightmp+1);
            treequeue.push(rtmp);
            heighqueue.push(heightmp+1);
        }
        TreeNodeAdd* htmp = NULL;
        TreeNodeAdd* ltmp = NULL;
        htmp = pheigh > qheigh ? ptmp:qtmp;
        ltmp = pheigh > qheigh ? qtmp:ptmp;
        // cout << pheigh << " " << qheigh << endl;
        // cout << htmp->ori->val << " " << ltmp->ori->val << endl;
        for(int i = 0;i < abs(pheigh-qheigh);i++){
            htmp = htmp->ancestor;
        }
        while(true){
            if(htmp->ori == ltmp->ori)
                break;
            htmp = htmp->ancestor;
            ltmp = ltmp->ancestor;
        }
        return htmp->ori;
    }
};