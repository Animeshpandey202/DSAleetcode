class Solution {
private:
int houseRobber(vector<int>& nums) {
// dynamic programming - decide each problem by its sub-problems:
int dp[nums.size()+1];
dp[0] = nums[0];
dp[1] = max(nums[0], nums[1]);
for (int i=2; i<nums.size(); i++)
dp[i] = max(dp[i-1], nums[i]+dp[i-2]);
return dp[nums.size()-1];
}
public:
int rob(vector<int>& nums) {
//if we pick 0 house cant pick last and vice-versa
vector<int> v1(nums.begin(), nums.end()-1);
vector<int> v2(nums.begin()+1, nums.end());
return max(houseRobber(v1), houseRobber(v2));
}
};