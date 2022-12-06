class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        auto temp=intervals[0];
        cout<<temp[0]<<temp[1]<<" ";
        int count=0;
        
        
        for(int i=1;i<intervals.size();i++){
            cout<<intervals[i][0]<<intervals[i][1]<<" ";
            
            if(temp[1]>intervals[i][0]){
                count++;
                //if temp=[1,6]  and interval[i] =[2,4] there is overlap but delete big intrvl i.e [1,6]
                if(temp[1]>intervals[i][1]){
                    temp=intervals[i];
                }
                
            }
            else{
                temp=intervals[i];
            }
        }
        return count;
        
    }
};