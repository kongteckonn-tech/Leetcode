/*
Pattern: Binary Tree (DFS + Recursion)

Approach:
- Use DFS to calculate the height of each node.
- For every node, calculate the maximum depth of its
  left subtree and right subtree.
- The longest path passing through the current node is:
    left depth + right depth
- Update `ans` with the largest diameter found.
- Return the height of the current node to its parent:
    1 + max(left depth, right depth)

Key Insight:
- The diameter does NOT necessarily pass through the root.
- Every node can be the middle point of the longest path.
- `ans` stores the maximum diameter found so far.
- The recursive function returns height, while `ans`
  records the diameter.

Example:
        1
       / \
      2   3
     / \
    4   5

At node 2:
- left depth = 1
- right depth = 1
- diameter = 1 + 1 = 2

At node 1:
- left depth = 2
- right depth = 1
- diameter = 2 + 1 = 3

Result: 3

Complexity:
- Time: O(n)
    - Every node is visited once.
- Space: O(h)
    - `h` is the height of the tree due to recursion.

Takeaway:
- Diameter = `left depth + right depth`
- Height = `1 + max(left depth, right depth)`
- Update the answer at every node.
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
    int ans = 0;
    int depth(TreeNode* root)
    {
        if (!root)
            return 0;
        int left = depth(root->left);
        int right = depth(root->right);
        ans = max(ans, left + right);
        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root)
    {
        depth(root);
        return ans;
    }
};
