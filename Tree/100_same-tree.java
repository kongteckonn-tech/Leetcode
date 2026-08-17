/*
Pattern: Binary Tree (DFS + Recursion)

Approach:
- Compare the two trees at the same time using recursion.
- If both nodes are `null`, they are the same at this position.
- If one node is `null` and the other is not, the trees are different.
- If the two node values are different, return `false`.
- Recursively compare the left subtrees and right subtrees.
- Both left and right subtrees must be the same.

Key Insight:
- Two binary trees are the same only when:
    1. Their corresponding node values are the same.
    2. Their structures are the same.
- `p.left` must match `q.left`.
- `p.right` must match `q.right`.
- Using `&&` ensures both sides must be identical.

Complexity:
- Time: O(n)
    - Each corresponding node is visited once.
- Space: O(h)
    - `h` is the height of the tree because of recursion.

Takeaway:
- Same Tree
  → Compare corresponding nodes.
- Both null → same.
- One null → different.
- Values different → different.
- Otherwise → recursively compare left and right.
*/
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if (p == null && q == null) return true;
        if ((p == null && q != null) || (q == null && p != null) || (p.val != q.val))
            return false;
        return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
    }
}
