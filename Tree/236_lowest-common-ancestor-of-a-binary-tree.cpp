/*
Pattern: Binary Tree (DFS + Recursion)

Approach:
- Use DFS to search for `p` and `q`.
- If `root` is `NULL`, return `NULL`.
- If `root` is `p` or `q`, return `root`.
- Recursively search the left and right subtrees.
- Receive the results using `left` and `right`.
- If both `left` and `right` are not `NULL`, it means
  `p` and `q` are found on different sides.
  Therefore, the current `root` is their Lowest Common Ancestor.
- If only `left` is found, return `left`.
- If only `right` is found, return `right`.
- If neither side is found, return `NULL`.

Key Insight:
- `left` and `right` are the information returned from
  the two subtrees.
- `left && right` → p and q are on different sides →
  current `root` is the answer.
- Only one side has a result → continue returning that result.
- `Lowest` means the closest common ancestor to `p` and `q`.

Complexity:
- Time: O(n)
    - Each node is visited at most once.
- Space: O(h)
    - `h` is the height of the tree because of recursion.

Takeaway:
- LCA
  → Search Left + Search Right.
- Both found → `root`.
- Left found → `left`.
- Right found → `right`.
- Nothing found → `NULL`.
*/
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL)
            return NULL;
        if (root == p || root == q)
            return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left && right)
            return root;
        if (left)
            return left;
        return right;
    }
};
