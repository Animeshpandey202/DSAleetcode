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
    int kthSmallest(TreeNode* root, int k) {
        // tc==O(N) and sc=O(1)
        
        TreeNode *cur=root;
        int ans;
        int count=0;
        //inoreder trvrsl = 1,2,3,4,5,6
        while(cur){
            
            if(cur->left==NULL){
                count++;
                if(count==k){
                    ans=cur->val;
                }    
                cur=cur->right;
                
            }
            else{
                
                TreeNode *prev=cur->left;
                
                while(prev->right && prev->right!=cur){
                    prev=prev->right;
                }
                
                if(prev->right==NULL){
                    
                    prev->right=cur;
                    cur=cur->left;
                }
                else{
                    prev->right=NULL;
                    count++;
                    if(count==k){
                        ans=cur->val;
                    }
                    cur=cur->right;
                    
                }
                
            }   
        }
        
      return ans;
        
    }
};



// Kth largest element can be done in single traversal. By using reverse inorder traversal i.e.(Right-Node-Left) .Then we can easily figure out kth largest element in single traversal.
// Just require few modification in code:
// int kthLargest(TreeNode* root, int k) {
//         stack<TreeNode*> st; 
//         TreeNode* node = root;
//         int cnt = 0; 
//         while(true) {
//             if(node != NULL) {
//                 st.push(node); 
//                 node = node->right; 
//             }
//             else {
    
//                 if(st.empty() == true) break; 
//                 node = st.top(); 
//                 st.pop(); 
                
//                 cnt++; 
//                 if(cnt == k) return node->val; 
//                 node = node->left; 
//             }  
//         }
//         return -1;
//     }