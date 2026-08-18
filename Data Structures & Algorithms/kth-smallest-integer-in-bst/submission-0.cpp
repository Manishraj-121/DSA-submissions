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
    void f(TreeNode* root, vector<int> &arr){
        if(root==nullptr)return;
        arr.push_back(root->val);

        f(root->left, arr);
        f(root->right, arr);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int>arr;
        f(root,arr);
        sort(arr.begin(),arr.end());
        return arr[k-1];
    }
};
