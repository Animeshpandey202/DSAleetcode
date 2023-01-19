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

//tc=O(n) sc=O(N)recusrion stack
class Solution {
   
private:
    TreeNode *prev,*first,*last;
    
   
private:
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        if(prev!=NULL && (root->val<prev->val)){
            if(first==NULL){
                first=prev;
                last=root; 
            }
            else
                last=root;
        }
        prev=root;
        inorder(root->right);
    }
    public:
    void recoverTree(TreeNode* root) {
        first=last=prev=NULL;
        inorder(root);
        swap(first->val,last->val);
    }
};


// using morris traversal tc=O(N) sc=O(1)
// class Solution {
    
// private:
//     TreeNode *prev,*first,*second;
    
// private:
    
//     void verifyNode(TreeNode* node){
	
// 	// check if previous pointer == null or node values are correct inorder traversal i.e prev is smaller than current node
//         if(prev == nullptr || (prev->val<node->val)){ 
//             prev = node;
//             return;
//         }
        
//         if(first == nullptr ){
//             first = prev;
//             second = node;
//         }else{ 
//             second = node;
//         }
//     }
//     void morrisInorder(TreeNode* root){
//         if(!root)return;
//         while(root){
//             if(root->left == nullptr){
//                 verifyNode(root);
//                 root = root->right;
//             }else{
//                 TreeNode* iter = root->left;
//                 // find predecessor
//                 while(iter->right && iter->right!=root){
//                     iter = iter->right;
//                 }
                
//                 if(iter->right == nullptr)//create morris thread
//                 {
//                     iter->right = root;
//                     root = root->left;
//                 }else{
//                     iter->right = nullptr;
//                     verifyNode(root);
//                     root = root->right;
//                 }
//             }
//         }
//     }
//     public:
//     void recoverTree(TreeNode* root) {
//         first=second=prev=NULL;
//         morrisInorder(root);
//         swap(first->val, second->val);
//     }
// };
