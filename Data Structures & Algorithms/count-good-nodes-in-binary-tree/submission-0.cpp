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
    void f(TreeNode* root, int &count, int maxi){
        if(root==nullptr)return ;
        
        if( maxi <= root->val){
            count++;
            maxi=root->val;
        }
        //leftward
        f(root->left, count, maxi);
        
        //rightward
        f(root->right, count, maxi);

    }
public:
    int goodNodes(TreeNode* root) {
        int count=0;
        int maxi=root->val;
        f(root, count, maxi);
        return count;
    }
};
