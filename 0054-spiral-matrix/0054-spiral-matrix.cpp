class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int R=mat.size();
        int C=mat[0].size();
        vector<int>ans;
        int tot=R*C;
        int count=0;
     int top = 0, left = 0, bottom = R - 1, right = C - 1;

  while (count<tot) {
    for (int i = left; i <= right && count<tot; i++){
       ans.push_back(mat[top][i]); 
        count++;
    }
      

    top++;

    for (int i = top; i <= bottom && count<tot; i++){
     ans.push_back(mat[i][right]); 
        count++;
    
    }
     
    right--;

     
      for (int i = right; i >= left && count<tot; i--){
        ans.push_back(mat[bottom][i]);  
          count++;
      }
   

      bottom--;
   

      for (int i = bottom; i >= top && count<tot; i--){
         ans.push_back(mat[i][left]);    
          count++;
      }
       left++;

  }   
    return ans;
    }
};