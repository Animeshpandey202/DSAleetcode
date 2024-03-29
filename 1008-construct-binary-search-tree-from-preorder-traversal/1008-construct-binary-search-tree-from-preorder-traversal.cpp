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
    TreeNode* buildBST(vector<int>& preorder,int& index,int lowerBound,int upperBound){
        if(index>=preorder.size()) return NULL;
        if(preorder[index]<lowerBound || preorder[index]>upperBound) return NULL;
        
        TreeNode* node=new TreeNode(preorder[index++]);
        node->left=buildBST(preorder,index,lowerBound,node->val);
        node->right=buildBST(preorder,index,node->val,upperBound);
        return node;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index=0;
        return buildBST(preorder,index,INT_MIN,INT_MAX);
    }
};
// brute
 // if(!root) return new TreeNode(key);
 //        if(key>root->val)   root->right=insertNode(root->right,key);
 //        else    root->left=insertNode(root->left,key);
 //        return root;
 //    }
 //    TreeNode* bstFromPreorder(vector<int>& preorder) {
 //        TreeNode* root=new TreeNode(preorder[0]);
 //        for(int i=1;i<preorder.size();i++)
 //            insertNode(root,preorder[i]);
        // return root;  