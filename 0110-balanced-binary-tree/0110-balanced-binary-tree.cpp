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
    // tc=O(n) sc=O(n)
    
    int f(TreeNode *root){

        if(root==NULL)return 0;
        
        int lheight=f(root->left);
        int rheight=f(root->right);
        
        if(abs((rheight-lheight))>1)return -1;
  
        if(lheight==-1 ||rheight ==-1)return -1;
        

        return 1+ max(lheight,rheight);
        
    }    
    
public:
    bool isBalanced(TreeNode* root) {   
        return f(root)!=-1;
        
    }
};








