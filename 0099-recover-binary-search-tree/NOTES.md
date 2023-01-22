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
​
​
​
class Solution {
private:
TreeNode *prev,*first,*last;
private:
void inorder(TreeNode* root){