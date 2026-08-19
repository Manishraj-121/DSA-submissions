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
    int f(TreeNode* root, int &maxi) {
        if (root == nullptr) return 0;

        int left = root->val + max(0, f(root->left, maxi));
        int right = root->val + max(0, f(root->right, maxi));

        maxi = max(maxi, left + right - root->val);

        return max(left, right);
    }

   public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;

        f(root, maxi);
        return maxi;
    }
};
