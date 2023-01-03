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
    vector<vector<int>> verticalTraversal(TreeNode* root) { 

   vector<vector<int>>ans;
  if(!root) return ans;

  map<int,map<int,multiset<int>>> nodes;
  queue<pair<TreeNode* , pair<int,int>>> todo;

  todo.push({root,{0,0}});

  while(!todo.empty()){
      int size=todo.size();
      
      while(size--){    
            auto p = todo.front();
            todo.pop();
            TreeNode* node = p.first;
            int x = p.second.first , y = p.second.second;

            nodes[x][y].insert(node->val);

            if(node->left){
              todo.push({node->left , {x-1 , y+1}});
            }
            if(node->right){
              todo.push({node->right , {x+1 , y+1}});
            }
      }
  }
  
  for(auto p:nodes){  //p=map<int,map<int,multiset<int>>> nodes;
    
    vector<int>col;
    
    for(auto q:p.second){   // q=map<int,multiset<int>>
       col.insert(col.end(), q.second.begin(), q.second.end());
    }
   
    ans.push_back(col);
  }
  return ans;

    }
};


//3. Insert Another Vector
// Further, we can also insert elements of another vector to our old vector. Just we need to pass an iterator pointing to the position in our vector where we need to insert another vector. Along with that, the iterators pointing to the starting and end of the second vector.

// Let us take a small example to understand the working.

// #include<iostream>    
// #include<vector> 
// using namespace std;
// int main()
// {  
// 	vector<int> vec {2,4,6,8};
// 	vector<int> vec2 {1,3,5,7};
// 	cout<<"Intially first vector: ";
// 	for(auto i=vec.begin(); i<vec.end(); i++)
// 	{
// 		cout<<" "<<*i;
// 	}
// 	cout<<"\nIntially second vector: ";
// 	for(auto i=vec2.begin(); i<vec2.end(); i++)
// 	{
// 		cout<<" "<<*i;
// 	}
	
// 	//Inserting vec2 at the beginning of the vec vector
// 	vec.insert(vec.begin(),vec2.begin(),vec2.end());
	
// 	cout<<"\n\nThe modified vector is: ";
// 	for(auto i=vec.begin(); i<vec.end(); i++)
// 	{
// 		cout<<" "<<*i;
// 	}
// 	return 0;
// }
// Output;

// Intially first vector:  2 4 6 8
// Intially second vector:  1 3 5 7

// The modified vector is:  1 3 5 7 2 4 6 8
// Here, vec and vec2 are two vectors. Out of which vec2 is the one whose elements we need to insert into the vector, vec. We call the insert() function with appropriate parameters as mentioned earlier. This modifies our vector vec, resulting in the insertion of the second vector elements at the beginning.