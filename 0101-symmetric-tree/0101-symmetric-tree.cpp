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
    bool solve(TreeNode *leftc,TreeNode *rightc){
        if(rightc==NULL || leftc==NULL){
            return leftc==rightc;
        }
        
        if(leftc->val != rightc->val)return false;
        
        return solve(leftc->left,rightc->right) && solve(leftc->right,rightc->left);
        
        
        
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)return true;
        
        return solve(root->left,root->right);
        
    }
};