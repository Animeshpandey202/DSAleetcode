
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //TC=O(nlogn)  SC=O(N)
        if(n==0)return tasks.size();
        
        unordered_map<char,int>mp;
        for(auto it:tasks){
            //adding the count of every character to the map
            mp[it]++;
        }
        priority_queue<int>pq;
        for(auto it:mp){
            pq.push(it.second);
        }
        int ans=0;
        
        while(!pq.empty()){
             //v will store type of task done in a cooldown time
            vector<int>v;
            
            //add tasks
            //if cooldown time is 2...then 3 type of task can be done in this time....if 4 then 5 type task
            
            for(int i=0;i<=n;i++){
                if(!pq.empty()){
                    v.push_back(pq.top());
                    pq.pop();
                }
            }
            
            
            
            //if tasks left to be done add back to pq
            for(auto it:v){
                //if after running a type of task for 1 time its still left...again push in pq
                if(--it>0){
                    pq.push(it);
                }
            }
            
            //add to ans
            //exp if tasks= A B  and n=2 then both task processed in 1st cooldown period with 1unit time remaining ....therefore ans+= no.of task ... dry run 1st exp
            
            ans+= (pq.empty()==true)?v.size():n+1;
        }
        return ans;
    }
};

  