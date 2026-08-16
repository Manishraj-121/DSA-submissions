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





// in this question i want to calculate the is it balance 
// step1 : first of all i try to find the max height of left and also for height and at this moment i check/find the condition for this current node and i will store it in another variable and i will return the max of left and right



// Step 1: Find the height of the left and right subtrees.
//
// Step 2: At the current node, check whether the difference
// between the left and right subtree heights is greater than 1.
// If it is, the tree is unbalanced.
//
// Step 3: Return the height of the current subtree,
// which is 1 + max(leftHeight, rightHeight).
class Solution {
private: 
    int f(TreeNode* root , int &ans){
        if(root==nullptr)return 0;

        int l=f(root->left,ans);
        int r=f(root->right,ans);

        if(abs(l-r)>1){
            ans++;
        }
        
        return 1+max(l,r);
    }
public:
    bool isBalanced(TreeNode* root) {
        int ans=0;
       f(root,ans);
       if(ans>0)return false;
       return true;
    }
};
