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
    void PreStore(vector<int>& cur, TreeNode* root)
    {
        if (!root)
            return;
        cur.push_back(root->val);
        PreStore(cur, root->left);
        PreStore(cur, root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret{};
        PreStore(ret, root);
        return ret;
    }
};
