/*
Pattern: Binary Tree + DFS

Approach:
- Left
- Root
- Right

Key Insight:
- Inorder = Left → Root → Right.
- BST inorder → ascending order.

Complexity:
- Time: O(n)
- Space: O(h)

Takeaway:
- Inorder → Left first, Root second, Right last.
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
    public List<Integer> inorderTraversal(TreeNode root) {
        if (root == null)
            return Tree;
        inorderTraversal(root.left);
        Tree.add(root.val);
        inorderTraversal(root.right);
        return Tree;
    }
}
