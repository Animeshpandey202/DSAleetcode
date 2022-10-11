class MinStack {
public:
    stack<long long> st;
    long long min=INT_MAX;
    
    MinStack() {
        while(st.empty()==false){
            st.pop();
        }
    }
    
    void push(int val) {
        long long el=val;
        if(st.empty()==1){
            st.push(val);
            min=el;
            
        }
        else{
            if(el<min){
                st.push(2*el-min);
                min=el;
            }
            else{
                st.push(el);
            }
            
        }
        
    }
    
    void pop() {
        
        long long el=st.top();
        
        if(el<min){
            min=2*min-el;   
            st.pop();
        }
        else{
            st.pop();
        }
        
        
    }
    
    int top() {
        long long el=st.top();
        if(st.top()<min){
            return min;
        }
        else return el;
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */