## 474. Lowest Common Ancestor II
#### Given the root and two nodes in a Binary Tree. Find the lowest common ancestor(LCA) of the two nodes.<br>The lowest common ancestor is the node with largest depth which is the ancestor of both nodes.<br>The node has an extra attribute parent which point to the father of itself. The root's parent is null.

>* Example
>> For the following binary tree:
```
  4
 / \
3   7
   / \
  5   6
```
>> LCA(3, 5) = 4
>> LCA(5, 6) = 7
>> LCA(6, 7) = 7