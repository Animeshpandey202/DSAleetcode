class Solution {
public:
	bool isNStraightHand(vector<int>& nums, int k) 
	{   if(nums.size()%k!=0)return false;
		map<int,int> mp;
		for(int i=0;i<nums.size();i++)
		{
			mp[nums[i]]++;
		}

		while(mp.size()>0)
		{
			int first=mp.begin()->first;
				for(int i=0;i<k;i++)
				{
					if(mp[first+i]>0)
					{
						mp[first+i]--;
                        if(mp[first+i]==0)mp.erase(first+i);
					}
					else{
                     return false;   
                    }
						
				}
		}


		return true;

	}
};