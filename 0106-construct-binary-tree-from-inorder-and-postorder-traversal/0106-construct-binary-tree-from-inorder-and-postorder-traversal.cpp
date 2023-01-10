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
    //tc=O(N) sc=O(n)
    TreeNode* solve(vector<int>& inorder,vector<int>& postorder,int start,int end,int &index){
        
        if(start>end) return NULL;
        
        TreeNode* root = new TreeNode(postorder[index]);  
        
        int pos = m[postorder[index]];
        
        (index)--;
        
        root->right=solve(inorder,postorder,pos+1,end,index);
        
        root->left=solve(inorder,postorder,start,pos-1,index);
        
        return root;
    }
    
 public:
      unordered_map<int,int>m;
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        for(int i=0;i<inorder.size();i++){
           m[inorder[i]] = i;
            
        }
        int Index=postorder.size()-1;
        return solve(inorder,postorder,0,postorder.size()-1,Index);
    }
};