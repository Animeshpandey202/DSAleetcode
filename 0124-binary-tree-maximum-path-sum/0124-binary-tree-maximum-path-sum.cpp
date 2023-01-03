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
    int solve(TreeNode *root,int &maxi){
        if(!root)return 0;
        
        int lsum=max(0,solve(root->left,maxi));
        int rsum=max(0,solve(root->right,maxi));
        
        //when we consider root as curving point
        maxi=max(maxi,root->val +lsum+rsum);
        
        //when we dont consider curr root as curving pont thrn
        
        return root->val+max(lsum,rsum);
            
    }
    
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        solve(root,maxi);
        return maxi;
    }
};