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
        
        n = nums.size();

        ll inf  = 1e5;

        vector<ll> hash(n+2, inf);
        ll ans = 0;
        hash[0] = -inf;

        for(int i=0; i<n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if( (hash[j] > nums[i]) && (hash[j-1] < nums[i])  )
                {
                    hash[j] = nums[i];
                }
            }
        }

        for(int i=0; i<=n+1; i++)
        {
            if(hash[i]==inf)
            return i-1;
        }
        return ans;
    }
};