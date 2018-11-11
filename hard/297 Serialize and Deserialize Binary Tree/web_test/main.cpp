class Codec {
public:
 
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        serialize(root, s);
        return s;
    }
 
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) { 
        int pos = 0;
        return deserialize(data, pos);
    }
private:
    enum STATUS {
        ROOT_NULL = 0x0,
        ROOT = 0x1,
        LEFT = 0x2,
        RIGHT = 0x4
    };
    
    void serialize(TreeNode* root, string& s) {
        char status = ROOT_NULL;
        if (root) status |= ROOT;
        if (root && root->left) status |= LEFT;
        if (root && root->right) status |= RIGHT;
        s.push_back(status);
        if (!root) return;
        s.append(reinterpret_cast<char*>(&root->val), sizeof(root->val));
        if (root->left) serialize(root->left, s);
        if (root->right) serialize(root->right, s);
    }
    
    TreeNode* deserialize(const string& s, int& pos) {
        char status = s[pos++];
        if (!status) return nullptr;
        TreeNode* root = new TreeNode(0);
        memcpy(&root->val, s.data() + pos, sizeof(root->val));
        pos += sizeof(root->val);  
        root->left = (status & LEFT) ? deserialize(s, pos) : nullptr;
        root->right = (status & RIGHT) ? deserialize(s, pos) : nullptr;
        return root;
    }
};

class Codec {
private:
    void encode(TreeNode* root, string& res) {
        if(root == NULL){
            res += "[#]";
            return;
        }
        res += '[';
        res += to_string(root->val);
        encode(root->left, res);
        encode (root->right, res);
        res += ']';
        return;

    }

    void decode(TreeNode* root, string& data, int& idx) {
        TreeNode* p;
        bool isleft = true;
        while (idx < data.size()) {
            if (data[idx] == '[')
                idx++;
            else if (data[idx] == '#') {
                if (isleft)
                    isleft = false;
                idx++;
                decode(NULL, data, idx);
            }
            else if (data[idx] == '+' || data[idx] == '-' || isdigit(data[idx])) {
                int start = idx;
                while (data[idx] == '+' || data[idx] == '-' || isdigit(data[idx]))
                    idx++;
                int val = stoi(data.substr(start, idx - start));
                p = new TreeNode(val);
                if (isleft){
                    root->left = p;
                    isleft = false;
                }
                else
                    root->right = p;
                decode(p, data, idx);
            }
            else if (data[idx] == ']') {
                idx++;
                return;
            }
        }
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        encode(root, res);
        cout <<res<<endl;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "[#]")
            return NULL;
        TreeNode* dummy = new TreeNode(0);
        int idx = 0;
        decode(dummy, data, idx);
        return dummy->left;
    }
};

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
        if (root == NULL) return "";
        string str;
        stack<TreeNode*> s;
        
        s.push(root);
        
        while (!s.empty()){
            TreeNode* cur = s.top();
            s.pop();
            
            if (cur == NULL){
                str.push_back('#');
                str.push_back(',');
                continue;
            }
            str.append(to_string(cur->val) + ",");
            s.push(cur->right);
            s.push(cur->left);
            
        }
        return str;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") return NULL;
        vector<string> process_data;
        int start = 0;
        int pos = 0;
        for (int i = 0; i < data.length(); i++){
            if (data[i] == ','){
                string cur = data.substr(start, i-start);
                process_data.push_back(cur);
                start = i+1;
                //cout << cur << endl;
            }
        }
        return deserializehelper(process_data, pos);
        
    }
    
    TreeNode* deserializehelper(vector<string>& data, int& pos){
        if (pos >= data.size()) return NULL;
        
        string cur = data[pos++];
        if (cur == "#") return NULL;
        
        TreeNode* root = new TreeNode(atoi(cur.c_str()));
        
        root->left = deserializehelper(data, pos);
        root->right = deserializehelper(data, pos);
        
        
        return root;
    }
        
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));