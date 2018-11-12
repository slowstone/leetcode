
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
        int start = 1,len = 0;
        TreeNode *res = new TreeNode(0);
        TreeNode *cur = res;
        int leftorright = 1;
        queue<TreeNode *> tq;
        for(int i = 0;i < data.size();i++){
            char s = data[i];
            if(s == '[')
                continue;
            else if(s == ',' || s == ']'){
                string stmp = data.substr(start,len);
                if(stmp != "#"){
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
                }
                if(leftorright == 2){
                        cur = tq.front();
                        tq.pop();
                        leftorright = 0;
                    }
                leftorright++;
                start = start + len + 1;
                len = 0;
            }
            else{
                len++;
            }
        }
        return res->right;
    }
};