//{ Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int pageFaults(int n, int c, int pages[]){
        unordered_map<int,int>mp;
        unordered_set<int>s;
        int fault=0;
        for(int i=0;i<n;i++){
            
            // space left
            if(s.size()<c){
                //space left and element not found
                if(s.find(pages[i])==s.end()){
                    s.insert(pages[i]);
                    mp[pages[i]]=i;
                    fault++;
                }
                else{ //space present and el found
                    mp[pages[i]]=i;
                }
            }
            else{ //space filled
               
                //no space and el not found 
                if(s.find(pages[i])==s.end()){
                    //remove the least recently used el
                    int mini=INT_MAX;
                    int lru_el;
                    for(auto it:mp){
                        if(it.second<mini){
                            mini=it.second;
                            lru_el=it.first;
                        }
                    }
                    mp.erase(lru_el);
                    s.erase(lru_el);
                    
                    //insert new el and assign its index
                    mp[pages[i]]=i;
                    s.insert(pages[i]);
                    fault++;
                }
                else{
                    //no space and el found
                    mp[pages[i]]=i;
                    
                }
                
            }
            
        }
        return fault;
    }
};


// unordered_set<int> s;
//     	unordered_map<int, int> indexes;
    
//     	int page_faults = 0;
//     	for (int i = 0;i < N; i++){
//     		if (s.size() < C){
//     			if (s.find(pages[i]) == s.end()){
//     				s.insert(pages[i]);
//     				page_faults++;
//     			}
//     			indexes[pages[i]] = i;
//     		}
//     		else{
    		    
//     			if (s.find(pages[i]) == s.end()){
//     				int lru = INT_MAX, val;
//     				for (auto it :s){
//     					if (indexes[it] < lru){
//     						lru = indexes[it];
//     						val = it;
//     					}
//     				}
//     				s.erase(val);
//     				s.insert(pages[i]);
//     				page_faults++;
//     			}
    			
//     			indexes[pages[i]] = i;
//     		}
//     	}
    // 	return page_faults;

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
}
// } Driver Code Ends