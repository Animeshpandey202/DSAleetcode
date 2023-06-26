class Solution {
public:
    double myPow(double x, int n) {
        
        double ans=1;
        long nn=n;  //we take long as value of n is integer and if its negative then -1*n will overflow
        
        if(nn<0){
            nn=nn*-1;
        }    
            
        while(nn>0){
            
            if(nn%2==0){
                //even power 
                x=x*x;
                nn=nn/2;
                
            }
            else{
                //odd power
                
                ans=ans*x;
                nn=nn-1;
            }
        }
        
        if(n<1){
            ans= (double)(1.0)/(double)(ans);
        }
        
        return ans;
        
    }
};