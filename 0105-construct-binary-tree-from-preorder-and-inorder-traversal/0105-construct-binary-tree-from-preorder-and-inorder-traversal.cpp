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
        TreeNode* build(vector<int>&pr,vector<int>& in,int start,int end,int &index,map<int,int>&mp){
        
              if(start>end)return NULL;
            
            TreeNode *root=new TreeNode(pr[index]);
              
            int pos=mp[pr[index++]];
            
            root->left=build(pr,in,start,pos-1,index,mp);
            
            root->right=build(pr,in,pos+1,end,index,mp);
            
            return root;
    }
  
    
    
public:
    TreeNode* buildTree(vector<int>& pr, vector<int>& in) {
        
        map<int,int>mp;
        //map index of inorder elem
        int n=in.size();
        int index=0;
        
        for(int i=0;i<n;i++){
            mp[in[i]]=i;
        }
     
        TreeNode *root=build(pr,in,0,pr.size()-1,index,mp);
        return root;
        
        
    }
};