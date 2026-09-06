/*
Pattern: Binary Tree + DFS

Approach:
- Root
- Left
- Right

Key Insight:
- Preorder = Root → Left → Right.

Complexity:
- Time: O(n)
- Space: O(h)

Takeaway:
- Preorder → Root first.
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
    private List<Integer> Tree = new ArrayList<>();
    public List<Integer> preorderTraversal(TreeNode root) {
        if (root == null)
            return Tree;
        Tree.add(root.val);
        preorderTraversal(root.left);
        preorderTraversal(root.right);
        return Tree;
    }
}
