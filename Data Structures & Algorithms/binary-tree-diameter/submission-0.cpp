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
    int f(TreeNode* root, int& ans){
        if(root==nullptr)return 0;
        
        int l=f(root->left , ans);
        int r=f(root->right , ans);
        ans=max(ans, l + r);
        return 1+max(l,r);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        f(root, ans);
        return ans;
    }
};
