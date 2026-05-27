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
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        int maxL = maxDepth(root->left);
        int maxR = maxDepth(root->right);
        return maxL > maxR ? maxL + 1 : maxR + 1;
    }
    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;
        int L = maxDepth(root->left);
        int R = maxDepth(root->right);
        int max = L > R ? L : R;
        int min = L < R ? L : R;
        return (max - min <= 1) && isBalanced(root->left) && isBalanced(root->right);
    }
};
