/*
Pattern: Binary Tree + DFS

Approach:
- Left
- Right
- Root

Key Insight:
- Postorder = Left → Right → Root.

Complexity:
- Time: O(n)
- Space: O(h)

Takeaway:
- Postorder → Root last.
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
    public List<Integer> postorderTraversal(TreeNode root) {
        if (root == null)
            return Tree;
        postorderTraversal(root.left);
        postorderTraversal(root.right);
        Tree.add(root.val);
        return Tree;
    }
}
