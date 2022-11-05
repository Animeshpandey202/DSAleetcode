class Solution {
public:
string minWindow(string s, string t) {
    
    //This result variable will store the string which we will return
    string result;

    //It will check if any of the two string is empty and return empty string result
    if(s.empty() || t.empty()){
        return result;
    }

    //These 2 unorders maps will store frequency of characters in t string and windows
    unordered_map<char, int> mpt;
    unordered_map<char, int> mps;

    //It will update the frequency of each charater of string t int map;
    for(int i = 0; i < t.length(); i++){
        mpt[t[i]]++;
    }
    cout<<mpt['D'];

    //variable to store minimum length of result string
    int mini = INT_MAX;

    //counter
    int letterCounter = 0;
    int i=0;
    for(int j= 0;j < s.length(); j++){
        
        //This c variable will store each character of string s according to the fast pointer movement starting from 0
        char c = s[j];
        //store that character in current window and increase the counter by 1
        
        mps[c]++;
        //This if condition will execute only if there was need to fulfill required charters from map to window and increase             the letter counter
            if(mpt.find(c)!=mpt.end() && mps[c] <= mpt[c]){
                letterCounter++;
            }
      

        //This condition we have found the result in current window
        if(letterCounter == t.length()){
              //It will update the minimum required substring
            if(j-i + 1 < mini){
                mini = j - i + 1;
                //It will update the result string
                result = s.substr(i, mini);
            }
            
           //if extra character in window(el not in t or present in t but count in  s window more than t )
            while (mpt.find(s[i])==mpt.end() || mps[s[i]] > mpt[s[i]])
            {
                //This will start decreasing frequency of extra character in window
                mps[s[i]]--;

                //and move slow pointer
                i++;
            }

            //It will update the minimum required substring
            if(j-i + 1 < mini){
                mini = j - i + 1;
                //It will update the result string
                result = s.substr(i, mini);
            }
        }
    }
    return result;
}
};