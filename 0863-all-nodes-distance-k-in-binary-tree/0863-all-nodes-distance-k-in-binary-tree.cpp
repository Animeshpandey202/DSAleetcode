/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    // tc=O(n) sc=O(n)
    
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parentof) {
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) { 
            TreeNode* current = q.front(); 
            q.pop();
            
            if(current->left) {
                parentof[current->left] = current;
                q.push(current->left);
            }
            if(current->right) {
                parentof[current->right] = current;
                q.push(current->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        unordered_map<TreeNode*, TreeNode*> parentof; // node -> parent
        
        markParents(root, parentof); 
        
        unordered_map<TreeNode*, bool> visited; 
        
        queue<TreeNode*> queue;
        queue.push(target);
        
        visited[target] = true;
        int curr_level = 0;
        
        while(!queue.empty()) { /*Second BFS to go upto K level from target node and using our hashtable info*/
            
            int size = queue.size();
            
            if(curr_level== k) break;
            curr_level++;
            
            for(int i=0; i<size; i++) {
                
                TreeNode* current = queue.front(); 
                queue.pop();
                
                if(current->left && !visited[current->left]) {
                    queue.push(current->left);
                    visited[current->left] = true;
                }
                
                if(current->right && !visited[current->right]) {
                    queue.push(current->right);
                    visited[current->right] = true;
                }
                
                if(parentof[current] && !visited[parentof[current]]) {
                    queue.push(parentof[current]);
                    visited[parentof[current]] = true;
                }
                
            }
        }
        vector<int> result;
        while(!queue.empty()) {
            TreeNode* current = queue.front(); queue.pop();
            result.push_back(current->val);
        }
        return result;
    }
};