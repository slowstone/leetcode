/**
 * Definition of ParentTreeNode:
 * class ParentTreeNode {
 * public:
 *     int val;
 *     ParentTreeNode *parent, *left, *right;
 * }
 */


class Solution {
private:
    int height(ParentTreeNode * root, ParentTreeNode * target){
        if(root == NULL) return 0;
        if(root == target) return 1;
        int lh = height(root->left,target);
        int rh = height(root->right,target);
        return lh == 0 ? rh + 1 : lh + 1;
    }
public:
    /*
     * @param root: The root of the tree
     * @param A: node in the tree
     * @param B: node in the tree
     * @return: The lowest common ancestor of A and B
     */
    ParentTreeNode * lowestCommonAncestorII(ParentTreeNode * root, ParentTreeNode * A, ParentTreeNode * B) {
        // write your code here
        int a_height = height(root,A);
        int b_height = height(root,B);
        ParentTreeNode * ht = a_height > b_height ? A : B;
        ParentTreeNode * lt = a_height > b_height ? B : A;
        for(int i = 0;i < abs(a_height-b_height);i++){
            ht = ht->parent;
        }
        while(ht != lt){
            ht = ht->parent;
            lt = lt->parent;
        }
        return ht;
    }
};