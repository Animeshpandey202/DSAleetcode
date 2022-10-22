}
while(!s.empty()){
int top = s.top();
s.pop();
​
int start;
if(s.empty())
start = -1;
else
start = s.top();
int curr_area = histogram[top] * (n - start -1);
area = max(area, curr_area);
}
return area;
}
int maximalRectangle(vector<vector<char>>& matrix) {
int m=matrix.size();
if(m==0) return 0;
int n=matrix[0].size(), result=0;
vector<int> histogram(n, 0);
for(int i=0; i<m; i++){
for(int j=0; j<n; j++){
if(matrix[i][j]=='1')
histogram[j]+=1;
else
histogram[j]=0;
}
result = max(result, largestArea(histogram));
cout<<result<<" ";
}
return result;
}
};