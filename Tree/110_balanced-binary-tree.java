/*
Pattern: Binary Tree (DFS + Recursion)

Approach:
- Use `depth()` to calculate the height of the tree while
  checking whether the tree is balanced.
- Recursively calculate the left and right subtree heights.
- If either subtree returns `-1`, it means that subtree is
  already unbalanced, so immediately return `-1`.
- If the difference between the left and right heights is
  greater than 1, return `-1`.
- Otherwise, return the current tree height:
    1 + max(left, right)
- `isBalanced()` checks whether `depth(root)` returns `-1`.

Key Insight:
- Use `-1` as a special value to represent "unbalanced".
- This allows height calculation and balance checking to be
  done in the same DFS traversal.
- No need to repeatedly calculate the height of every subtree.

Example:
        1
       / \
      2   3
     /
    4

At every node:
- Calculate left height.
- Calculate right height.
- Check `|left - right| <= 1`.
- Return the height if balanced.
- Return `-1` immediately if unbalanced.

Complexity:
- Time: O(n)
    - Every node is visited once.
- Space: O(h)
    - `h` is the height of the tree because of recursion.

Takeaway:
- Balanced Binary Tree
  → DFS + Height + Early Stop.
- `-1` = unbalanced.
- Otherwise return the subtree height.
- `|left height - right height| > 1`
  → not balanced.
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
    public int depth(TreeNode root) {
        if (root == null)
            return 0;
        int left = depth(root.left);
        int right = depth(root.right);
        if (left == -1 || right == -1)
            return -1;
        if (Math.abs(left - right) > 1)
            return -1;
        return 1 + Math.max(left, right);
    }
    public boolean isBalanced(TreeNode root) {
        return depth(root) != -1;
    }
}
