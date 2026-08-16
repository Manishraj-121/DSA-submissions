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
    // m1 i can also solve with the help of ans variable that will be maintain at all node.
private: 
    bool f(TreeNode* p , TreeNode* q){
        if(p==nullptr && q==nullptr) return true;
        if(p==nullptr || q==nullptr) return false;

        if(p->val != q->val)return false;

       return  f(p->left, q->left) && f(p->right, q->right);
       
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
       
       return f(p,q);
       //if(ans>0)return false;
       //return true;
    }
};
