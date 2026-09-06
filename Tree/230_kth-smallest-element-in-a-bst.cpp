/*
Pattern: BST + Inorder

Approach:
- Inorder traversal of BST gives ascending order.
- Count each visited node.
- When count == k, current node is the kth smallest.

Key Insight:
- BST → Inorder = Small → Large.
- count == k → answer.

Complexity:
- Time: O(n)
- Space: O(h)

Takeaway:
- kth smallest BST → Inorder + Count.
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
    int count = 0;
    int ans = 0;
public:
    int kthSmallest(TreeNode* root, int k) {
        if (root == nullptr)
            return 0;
        kthSmallest(root->left, k);
        count++;
        if (count == k){
            ans = root->val;
            return ans;
        }
        kthSmallest(root->right, k);
        return ans;
    }
};
