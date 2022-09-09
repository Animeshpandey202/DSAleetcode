class Solution {
    bool alphanumeric(char c){
        
        return (c>='0'&& c<='9')|| (c>='A' && c<='Z') || (c>='a' && c<='z');
        
    }
    char lowercase(char c){
        
        if((c>='0'&& c<='9') ||  (c>='a' && c<='z'))return c;
        
        return (char)((int)(c)+32);
        
        
        
        
    }
    
public:
    bool isPalindrome(string s) {
        
        
        int i=0;
        int j=s.length()-1;
        
        while(i<j){
            
            if(!alphanumeric(s[i])){
                i++;
            }
            else if(!alphanumeric(s[j]))
            {
                j--;
            }
            else if(lowercase(s[i])!=lowercase(s[j])){
                return false;
            }
            else{
                i++;
                j--;
            }
            
        }
        return true;
        

    }
};