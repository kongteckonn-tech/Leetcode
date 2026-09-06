/*
Pattern: Binary Tree + Recursion + Divide & Conquer

Approach:
- preorder[0] is the root.
- Find the root in inorder.
- Left side of inorder → left subtree.
- Right side of inorder → right subtree.
- Recursively build both sides.

Key Insight:
- Preorder → tells us the Root.
- Inorder → tells us where to split.

Complexity:
- Time: O(n²)
- Space: O(n)

Takeaway:
- Preorder find Root.
- Inorder split Left / Right.
- Recursively build.
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) return NULL;
        int index = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();
        vector<int> inLeft(
        inorder.begin(), 
        inorder.begin() + index
        );
        vector<int> inRight(
        inorder.begin() + index + 1,
        inorder.end()
        );
        vector<int> preLeft(
        preorder.begin() + 1,
        preorder.begin() + 1 + index
        );
        vector<int> preRight(
        preorder.begin() + 1 + index,
        preorder.end()
        );
        TreeNode* root = new TreeNode(preorder[0]);
        root->left = buildTree(preLeft, inLeft);
        root->right = buildTree(preRight, inRight);
        return root;
    }
};
