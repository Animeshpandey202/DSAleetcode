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
    vector<int> inorderTraversal(TreeNode* root) {
        
 //morris traversal  tc=O(n) space=O(1)
        vector<int>ans;
         TreeNode* cur=root;
         while(cur!=NULL){
        
       
        
            if(cur->left==NULL){
                ans.push_back(cur->val);
                cur=cur->right;
                }
            else{
            
                TreeNode *pred=cur->left;
                while(pred->right!=NULL && pred->right!=cur){
                    pred=pred->right;
                        }
            
                if(pred->right==NULL){
                pred->right=cur;
                cur=cur->left;
                }
                
                else{
                pred->right=NULL;
                ans.push_back(cur->val);        //for preorder move this line after  line 33..ie pred->right=cur
                cur=cur->right;
                
                }
            }
         }
        return ans;
    }
};




            
            
            


//iterative inorder tc=O(n) sc-O(n)
//        vector<int>ans;
//         stack<TreeNode *>st;
//         TreeNode *node=root;
        
//         while(true){
            
//             if(node!=NULL){
//                 st.push(node);
//                 node=node->left;           

//             }
//             else{
                
//                 if(st.empty()==true)break;
                
//                 node=st.top();
//                 st.pop();
//                 ans.push_back(node->val);
//                 node=node->right;
                
                
//             }  
            
//         }
        
//         return ans;


//      iterative prorder
//         vector<int>ans;
//         if(root==NULL)return ans;
//         stack<TreeNode*>st;
//         st.push(root);
//         while(!st.empty()){
//             root=st.top();
            
        
//             st.pop();
//             ans.push_back(root->val);
            
//             if(root->right!=NULL)
//             st.push(root->right);
            
//             if(root->left!=NULL)
//             st.push(root->left);
            
            
            
//         }
        
//      return ans;  