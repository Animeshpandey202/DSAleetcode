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
public:
    void inorderTraversal(TreeNode* root,vector<int>&arr){
        
        if(root==NULL)
            return;
        
        inorderTraversal(root->left,arr);
        arr.push_back(root->val);
        inorderTraversal(root->right,arr);
    }
    
    void recoverBST(TreeNode* root, vector<int>&arr,int &i){
        if(root==NULL)
            return;
        
        recoverBST(root->left,arr,i);
        if(root->val != arr[i]){
            root->val = arr[i];
        }
          i++;
        recoverBST(root->right,arr,i);
      
    }
    
    void recoverTree(TreeNode* root) {
        vector<int>arr;
        inorderTraversal(root,arr);
        sort(arr.begin(),arr.end());
        // for(auto ar:arr)cout<<ar<<" ";
        int i = 0;
        recoverBST(root,arr,i);
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
