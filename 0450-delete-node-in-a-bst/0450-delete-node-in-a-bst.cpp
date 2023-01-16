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
        if(root) 
            if(key < root->val) root->left = deleteNode(root->left, key);     //We frecursively call the function until we find the target node
            else if(key > root->val) root->right = deleteNode(root->right, key);       
            else{
                if(!root->left && !root->right) return NULL;          //No child condition
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
                TreeNode *temp=root->left;
                while(temp->right != NULL) temp = temp->right;      
                root->val = temp->val;                            //       root->val = temp->val;
                root->left = deleteNode(root->left, temp->val);  //        root->right = deleteNode(root->right, temp);		
            }
        return root;
    }   
 
};