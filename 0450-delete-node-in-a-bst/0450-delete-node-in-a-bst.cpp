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
   TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) {
            return root;
        }    
        if(root->val==key){
            //No child condition
            if(!root->left && !root->right) {
                delete root;
                return NULL;          
            }
            //1child
            if (root->left && !root->right){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            if (!root->left && root->right){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } 
            
            //2child
            if (root->left && root->right){
                TreeNode *temp=root->left;
                while(temp->right != NULL) {
                    temp = temp->right;  
                }    
                root->val = temp->val;                            //       root->val = temp->val;
                root->left = deleteNode(root->left, temp->val);  
                return root;   //        root->right =  
            }      
        }
        else if(key < root->val){
           root->left = deleteNode(root->left, key); 
           return root; 
        } 

        else {
            root->right = deleteNode(root->right, key);
            return root;
        }     
        return root;
    }     
};