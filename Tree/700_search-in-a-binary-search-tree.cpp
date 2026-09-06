/*
Pattern: Binary Search Tree (DFS + Recursion)

Approach:
- Start from the root.
- If `root == nullptr`, the value does not exist.
- If `root->val == val`, return the current node.
- If not found, recursively search the left subtree.
- If left search returns `nullptr`, search the right subtree.

Key Insight:
- Your code treats the tree like a normal Binary Tree.
- It does NOT use the BST property:
    - `val < root->val` → go left.
    - `val > root->val` → go right.
- Therefore, your solution can search both sides.

Complexity:
- Time: O(n)
    - Worst case, every node may be visited.
- Space: O(h)
    - `h` is the height of the tree because of recursion.

Takeaway:
- Your approach:
  → DFS → Left → Right.
- Better BST approach:
  → Smaller → Left.
  → Larger → Right.
  → Equal → Found.
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
private:
    TreeNode* ans = nullptr;
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr)
            return root;
        if (val == root->val)
        {
            ans = root;
            return ans;
        }
        ans = searchBST(root->left, val);
        if (ans != nullptr)
            return ans;
        ans = searchBST(root->right, val);
        return ans;
    }
};
