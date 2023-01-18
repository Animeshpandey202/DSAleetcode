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
      TreeNode* insertNode(TreeNode* root,int key)
    {
        if(!root) return new TreeNode(key);
        if(key>root->val)   root->right=insertNode(root->right,key);
        else    root->left=insertNode(root->left,key);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root=new TreeNode(preorder[0]);
        for(int i=1;i<preorder.size();i++)
            insertNode(root,preorder[i]);
        return root;   
    }
};