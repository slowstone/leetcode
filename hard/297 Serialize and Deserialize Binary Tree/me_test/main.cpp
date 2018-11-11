/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "[]";
        string res("[");
        queue<TreeNode *> tq;
        tq.push(root);
        int len = 0;
        while(!tq.empty()){
            TreeNode *tmp = tq.front();
            tq.pop();
            string stmp;
            if(tmp == NULL)
                stmp = "#";
            else
                stmp = to_string(tmp->val);
            if(res == "[")
                res = res + stmp;
            else
                res = res + "," + stmp;
            if(tmp == NULL)
                continue;
            else
                len = res.size();
            tq.push(tmp->left);
            tq.push(tmp->right);
        }
        return res.substr(0,len) + ']';
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "[]") return NULL;
        string stmp;
        TreeNode *res = new TreeNode(0);
        TreeNode *cur = res;
        int leftorright = 1;
        queue<TreeNode *> tq;
        for(char s:data){
            if(s == '[')
                continue;
            else if(s == ',' || s == ']'){
                if(stmp == "#"){
                    if(leftorright == 2){
                        cur = tq.front();
                        tq.pop();
                        leftorright = 0;
                    }
                    leftorright++;
                    stmp.erase();
                    continue;
                }
                // cout << stmp << endl;
                int num = stoi(stmp);
                TreeNode *ttmp = new TreeNode(num);
                tq.push(ttmp);
                if(leftorright == 2){
                    cur = tq.front();
                    tq.pop();
                    leftorright = 0;
                }
                if(leftorright == 0)
                    cur->left = ttmp;
                else
                    cur->right = ttmp;
                stmp.erase();
                leftorright++;
            }
            else{
                stmp = stmp + s;
            }
        }
        return res->right;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));