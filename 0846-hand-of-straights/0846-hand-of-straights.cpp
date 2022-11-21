class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // create a min heap
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        // create unordered map to store integer counts
		unordered_map<int,int> mp;
        for(auto i:hand){
            mp[i]++;
        }
        
		// store {integer,count} in increasing order of integer in priority queue
        for(auto i:mp){
            pq.push(i);
        }
        
		// stack used for storing popped elements of min heap
        stack<pair<int,int>> st;
        while(pq.size()){
			// group size should be greater than min heap size
            if(pq.size()<groupSize) return false;
			int last=-1; // stores last stored integer popped from min heap 
            for(int i=0; i<groupSize; i++){
                auto top=pq.top();
                pq.pop();
				// check if last integer is set and current and last integers are not consecutive 
                if(last>=0 && top.first-last!=1) return false;
				last=top.first;  // store the current integer
				// push current {integer,count} if its count is greater than 1 
                if(top.second>1) st.push({top.first,top.second-1});
            }
			// push elements from stack back to queue
            while(!st.empty()){
                pq.push(st.top());
                st.pop();
            }
        }
        return true;
    }
};