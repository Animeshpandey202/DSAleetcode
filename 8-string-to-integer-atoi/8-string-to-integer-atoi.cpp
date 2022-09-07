class Solution {
public:
    int myAtoi(string s) {
        
        int sign=1;
        int i=0;
        long ans=0;
        
        while(s[i]==' ' && i<s.length()){
            i++;
        }
        
        if(s[i]=='+'|| s[i]=='-'){
            sign=s[i]=='-'?-1:1;
            i++;
        }


        
        while(i<s.length()){
            
            
            int c=s[i]-'0';
            
            if(c>=0 && c<=9){
                 ans=ans*10 +c*sign;
            
                if(sign==1 && ans>INT_MAX)return INT_MAX;
                if(sign==-1 && ans<INT_MIN)return INT_MIN;
                
            }
            else{
                break;       
            }
         
            i++;
        }
        return (int)ans;
        
    }
};