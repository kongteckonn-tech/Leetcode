/*
Pattern: Binary Tree / Complete Binary Tree (DFS + Recursion)

Approach:
- Original solution:
    - If `root == NULL`, return `0`.
    - Recursively count the left subtree.
    - Recursively count the right subtree.
    - Add `1` for the current root.
    - Formula:
        `left nodes + right nodes + 1`

- Optimized solution:
    - Calculate the height of the left and right subtrees.
    - If `hLeft == hRight`:
        → left subtree is a Perfect Binary Tree.
        → left subtree has `2^hLeft - 1` nodes.
        → recursively count the right subtree.
    - Otherwise:
        → right subtree is a Perfect Binary Tree.
        → right subtree has `2^hRight - 1` nodes.
        → recursively count the left subtree.
    - Add `1` for the current root.

Key Insight:
- Original solution counts every node.
- Complete Binary Tree has a special property:
    `hLeft == hRight`
    → left subtree is Perfect.

    `hLeft != hRight`
    → right subtree is Perfect.

- Perfect Binary Tree:
    `2^h - 1` nodes.

- Including the current root:
    `(2^h - 1) + 1 = 2^h`

Complexity:
- Original:
    Time: O(n)
    Space: O(h)

- Optimized:
    Time: O(log² n)
    Space: O(log n)

Takeaway:
- Original → DFS → count every node → O(n).
- Best → use Complete Binary Tree property → O(log² n).
- Equal height → count left directly → recurse right.
- Different height → count right directly → recurse left.
- Always remember `+1` for the current root.
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
    int height(TreeNode* root)
    {
        if (root == NULL)
            return 0;

        return 1 + max(height(root->left), height(root->right));
    }
    int countNodes(TreeNode* root) {
        // if (root == NULL)
        //     return 0;
        // return countNodes(root->left) + countNodes(root->right) + 1;
        if (root == NULL)
            return 0;
        int hLeft = height(root->left);
        int hRight = height(root->right);
        int ret = 0;
        if (hLeft == hRight)
        {
            ret = (1 << hLeft) - 1;
            return ret + countNodes(root->right) + 1;
        }
        else 
        {
            ret = (1 << hRight) - 1;
            return ret + countNodes(root->left) + 1;
        }
    }
};
