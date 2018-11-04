# Inorder Traversal

> There are three solutions to this problem.

>>1. Iterative solution using stack --- O(n) time and O(n) space;
>>2. Recursive solution --- O(n) time and O(n) space (considering the spaces of function call stack);
>>3. Morris traversal --- O(n) time and O(1) space!!!

>* Iterative solution using stack
```C++
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        stack<TreeNode*> todo;
        TreeNode* cur = root;
        while (cur || !todo.empty()) {
            if (cur) {
                todo.push(cur);
                cur = cur -> left;
            }
            else {
                cur = todo.top();
                todo.pop();
                nodes.push_back(cur -> val);
                cur = cur -> right;
            }
        }
        return nodes;
    }
};
```
>* Recursive solution
```C++
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        inorder(root, nodes);
        return nodes;
    }
private:
    void inorder(TreeNode* root, vector<int>& nodes) {
        if (!root) {
            return;
        }
        inorder(root -> left, nodes);
        nodes.push_back(root -> val);
        inorder(root -> right, nodes);
    }
};
```
>* Morris traversal
```C++
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
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* cur = root;
        vector<int> nodes;
        while (cur) {
            if (cur -> left) {
                TreeNode* pre = cur -> left;
                while (pre -> right && (pre -> right != cur)) {
                    pre = pre -> right;
                }
                if (!(pre -> right)) {
                    pre -> right = cur;
                    cur = cur -> left;
                } else {
                    pre -> right = NULL;
                    nodes.push_back(cur -> val);
                    cur = cur -> right;
                }
            } else {
                nodes.push_back(cur -> val);
                cur = cur -> right;
            }
        }
        return nodes;
    }
};
```

# Preorder Traversal

>* There are three solutions to this problem.

>>1. Iterative solution using stack --- O(n) time and O(n) space;
>>2. Recursive solution --- O(n) time and O(n) space (considering the spaces of function call stack);
>>3. Morris traversal --- O(n) time and O(1) space!!!

>* Iterative solution using stack
```C++
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> nodes;
        stack<TreeNode*> todo;
        TreeNode* cur = root;
        while (cur || !todo.empty()) {
            if (cur) {
                nodes.push_back(cur -> val);
                if (cur -> right) {
                    todo.push(cur -> right);
                }
                cur = cur -> left;
            } else {
                cur = todo.top();
                todo.pop();
            }
        }
        return nodes;
    }
};
```
>* Recursive solution
```C++
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> nodes;
        preorder(root, nodes);
        return nodes;
    }
private:
    void preorder(TreeNode* root, vector<int>& nodes) {
        if (!root) {
	    return;
	}
        nodes.push_back(root -> val);
        preorder(root -> left, nodes);
        preorder(root -> right, nodes);
    }
};
```
>* Morris traversal
```C++
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
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode* cur = root;
        vector<int> nodes;
        while (cur) {
            if (cur -> left) {
                TreeNode* pre = cur -> left;
                while (pre -> right && (pre -> right != cur)) {
                    pre = pre -> right;
                }
                if (!(pre -> right)) {
                    nodes.push_back(cur -> val);
                    pre -> right = cur;
                    cur = cur -> left;
                } else {
                    pre -> right = NULL;
                    cur = cur -> right;
                }
            } else {
                nodes.push_back(cur -> val);
                cur = cur -> right;
            }
        }
        return nodes;
    }
};
```

# Postorder Traversal

> There are three solutions to this problem.

>>1. Iterative solution using stack --- O(n) time and O(n) space;
>>2. Recursive solution --- O(n) time and O(n) space (considering the spaces of function call stack);
>>3. Morris traversal --- O(n) time and O(1) space!!!

>* Iterative solution using stack
```C++
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> nodes;
        stack<TreeNode*> todo;
        TreeNode* cur = root;
        TreeNode* last = NULL;
        while (cur || !todo.empty()) {
            if (cur) {
                todo.push(cur);
                cur = cur -> left;
            } else {
                TreeNode* top = todo.top();
                if (top -> right && (last != top -> right)) {
                    cur = top -> right;
                } else {
                    nodes.push_back(top -> val);
                    last = top;
                    todo.pop();
                }
            }
        }
        return nodes;
    }
};
```
>* Recursive solution
```C++
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> nodes;
        postorder(root, nodes);
        return nodes;
    }
private:
    void postorder(TreeNode* root, vector<int>& nodes) {
        if (!root) {
            return;
        }
        postorder(root -> left, nodes);
        postorder(root -> right, nodes);
        nodes.push_back(root -> val);
    }
};
```
>* Morris traversal
```C++
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> nodes;
        TreeNode* dummy = new TreeNode(0);
        dummy -> left = root;
        TreeNode* cur = dummy;
        while (cur) {
            if (cur -> left) {
                TreeNode* pre = cur -> left;
                while (pre -> right && (pre -> right != cur)) {
                    pre = pre -> right;
                }
                if (!(pre -> right)) {
                    pre -> right = cur;
                    cur = cur -> left;
                } else {
                    reverseAddNodes(cur -> left, pre, nodes);
                    pre -> right = NULL;
                    cur = cur -> right;
                }
            } else {
                cur = cur -> right;
            }
        }
        return nodes;
    }
private:
    void reverseNodes(TreeNode* start, TreeNode* end) {
        if (start == end) {
            return;
        }
        TreeNode* x = start;
        TreeNode* y = start -> right;
        TreeNode* z;
        while (x != end) {
            z = y -> right;
            y -> right = x;
            x = y;
            y = z;
        }
    }
    void reverseAddNodes(TreeNode* start, TreeNode* end, vector<int>& nodes) {
        reverseNodes(start, end);
        TreeNode* node = end;
        while (true) {
            nodes.push_back(node -> val);
            if (node == start) {
                break;
            }
            node = node -> right;
        }
        reverseNodes(end, start);
    }
};
```

# Summarization

>* Pre Order Traverse
```Java
public List<Integer> preorderTraversal(TreeNode root) {
    List<Integer> result = new ArrayList<>();
    Deque<TreeNode> stack = new ArrayDeque<>();
    TreeNode p = root;
    while(!stack.isEmpty() || p != null) {
        if(p != null) {
            stack.push(p);
            result.add(p.val);  // Add before going to children
            p = p.left;
        } else {
            TreeNode node = stack.pop();
            p = node.right;   
        }
    }
    return result;
}
```
>* In Order Traverse
```Java
public List<Integer> inorderTraversal(TreeNode root) {
    List<Integer> result = new ArrayList<>();
    Deque<TreeNode> stack = new ArrayDeque<>();
    TreeNode p = root;
    while(!stack.isEmpty() || p != null) {
        if(p != null) {
            stack.push(p);
            p = p.left;
        } else {
            TreeNode node = stack.pop();
            result.add(node.val);  // Add after all left children
            p = node.right;   
        }
    }
    return result;
}
```
>* Post Order Traverse
```Java
public List<Integer> postorderTraversal(TreeNode root) {
    LinkedList<Integer> result = new LinkedList<>();
    Deque<TreeNode> stack = new ArrayDeque<>();
    TreeNode p = root;
    while(!stack.isEmpty() || p != null) {
        if(p != null) {
            stack.push(p);
            result.addFirst(p.val);  // Reverse the process of preorder
            p = p.right;             // Reverse the process of preorder
        } else {
            TreeNode node = stack.pop();
            p = node.left;           // Reverse the process of preorder
        }
    }
    return result;
}
```
