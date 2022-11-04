//same as subarray sum equals k
int n=nums.size();
int prefix[n];
prefix[0]=nums[0];
for(int i=1;i<n;i++){
prefix[i]=nums[i]+prefix[i-1];
}
unordered_map<int,int> mp;
int count =0;
for(int i=0;i<n;i++){
if(prefix[i]==k)
{
count++;
}
int target=prefix[i]-k;
if(mp.find(target)!=mp.end()){
count+=mp[target];
}
mp[prefix[i]]++;
}
return count;