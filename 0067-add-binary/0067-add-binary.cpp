class Solution {
public:
    string addBinary(string a, string b) {
      int i=a.length()-1;
      int j=b.length()-1;
      string ans;
      int carry=0;
        
      while(i>=0 || j>=0 ||carry!=0){
            
            int sum=carry;
            
            if(i>=0)sum+=a[i--]-'0';
            if(j>=0)sum+=b[j--]-'0';
            
            if(sum>1){
                carry=1;
            }
            else{
                carry=0;
               
            }  
             ans+=to_string(sum%2);
        }
        
     
        string res=ans;
        reverse(res.begin(),res.end());
        return res;
    }
};