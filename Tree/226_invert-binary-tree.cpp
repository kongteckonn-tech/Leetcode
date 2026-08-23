/*
Pattern: Binary Tree (DFS + Recursion)

Approach:
- Use recursion to invert the left and right subtrees.
- For every node, swap its left and right children.
- Recursively invert the left subtree and temporarily
  store the result in `tmp`.
- Recursively invert the right subtree and assign it
  to `root->left`.
- Assign the saved left subtree to `root->right`.
- If `root` is `nullptr`, stop and return it.
- Return `root` after the whole tree has been inverted.

Key Insight:
- Inverting a binary tree means swapping the left and
  right subtree of every node.
- The same operation can be applied recursively to
  every subtree.
- `tmp` temporarily stores the inverted left subtree
  while the right subtree is being processed.

Complexity:
- Time: O(n)
    - Every node is visited once.
- Space: O(h)
    - `h` is the height of the tree because of recursion.

Takeaway:
- Invert Binary Tree
  → DFS + Recursion.
- Invert left subtree.
- Invert right subtree.
- Swap left and right.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
            return root;
        TreeNode* tmp = invertTree(root->left);
        root->left = invertTree(root->right);
        root->right = tmp;
        return root;
    }
};
