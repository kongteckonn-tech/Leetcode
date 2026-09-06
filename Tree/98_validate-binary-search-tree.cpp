/*
Pattern: BST + Inorder

Approach:
- Use inorder traversal.
- Compare current value with previous value.
- A valid BST must have strictly increasing inorder values.

Key Insight:
- previous >= current → invalid.

Complexity:
- Time: O(n)
- Space: O(h)

Takeaway:
- Validate BST → Inorder must be strictly increasing.
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
    bool hasCompare = false;
    int compare;
    bool Inorder(TreeNode* root){
        if (root == nullptr)
            return true;
        bool check1 = Inorder(root->left);
        if (hasCompare && (compare >= root->val))
            return false;
        compare = root->val;
        hasCompare = true;
        bool check2 = Inorder(root->right);
        return check1 && check2;
    }
public:
    bool isValidBST(TreeNode* root) {
        hasCompare = false;
        return Inorder(root);
    }
};
