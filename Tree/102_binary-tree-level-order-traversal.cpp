/*
Pattern: Binary Tree (DFS + Recursion)

Approach:
- Use DFS recursion to traverse the binary tree.
- Use `index` to represent the current level of the node.
- `ret[index]` stores all node values belonging to that level.
- If `index` reaches a new level, create a new vector.
- Otherwise, add the node value to the existing level.
- Recursively visit the left and right children with
  `index + 1`.
- Start the traversal from level `0`.

Key Insight:
- Although Level Order is commonly solved with BFS + Queue,
  this solution uses DFS.
- The recursion depth tells us which level the current
  node belongs to.
- Nodes are added to `ret[index]`, so nodes from the same
  level are grouped together.
- Because the left child is visited before the right child,
  values are stored in the correct left-to-right order.

Example:
        1
       / \
      2   3
     / \
    4   5

DFS:
- Level 0 → [1]
- Level 1 → [2, 3]
- Level 2 → [4, 5]

Result:
[[1], [2, 3], [4, 5]]

Complexity:
- Time: O(n)
    - Every node is visited once.
- Space: O(h)
    - `h` is the recursion depth.
    - The returned result itself requires O(n) space.

Takeaway:
- Level Order Traversal
  → DFS + Level Index.
- `index` = current tree level.
- `ret[index]` = values belonging to that level.
- Left → Right recursion preserves the order.
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
    void push(TreeNode* node, vector<vector<int>>& ret, int index)
    {
        if (node == NULL) return;
        if (index >= ret.size())
            ret.push_back({node->val});
        else
            ret[index].push_back(node->val);
        push(node->left, ret, index + 1);
        push(node->right, ret, index + 1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (root == NULL) return ret;
        push(root, ret, 0);
        return ret;
    }
};
