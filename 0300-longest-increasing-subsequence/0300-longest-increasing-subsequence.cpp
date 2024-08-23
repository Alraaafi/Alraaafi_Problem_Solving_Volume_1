#define ll long long int

ll const lim = 2507;
ll dp[lim];
ll arr[lim];
ll n;


ll LIS(ll i )
{
	if(i==n) return 0;
	if(dp[i] != -1 ) return dp[i];

	ll ans = 1;
	//cout<<arr[2];

	for(int j=i+1; j<n; j++)
	{
		if(arr[i] < arr[j] )
		{
			ans = max( ans, 1 + LIS(j) );
		}
	
	}

	return dp[i] = ans;
}

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        n = nums.size();
        for(int i=0; i<n; i++)
        arr[i] = nums[i];

        ll ans = 0;

        for(int i=0; i<n; i++)
        ans = max(ans, LIS(i));

        return ans;
    }
};