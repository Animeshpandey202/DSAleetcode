class Solution {
public:
   vector<int> asteroidCollision(vector<int>& ast) {
	stack<int> st;
	int size = ast.size();
	for(int i=0;i<size;i++) {
		
        if(ast[i]>0){
            st.push(ast[i]);
        }
        else{
            //ast[i]= -ve exp -5
            
            while(!st.empty() && st.top()<abs(ast[i]) && st.top()>0 ){
                st.pop();
            }
            
        //top= 8  a=-2
            if(st.empty() || st.top()<0){
                st.push(ast[i]);
            }
            if(st.top()==abs(ast[i])){
                st.pop();
            }
               
        }
	}
	vector<int> result(st.size(), 0);
	for (int i = result.size() - 1; i >= 0; i--) {
		result[i] = st.top();
		st.pop();
	}
	return result;
   }    
};