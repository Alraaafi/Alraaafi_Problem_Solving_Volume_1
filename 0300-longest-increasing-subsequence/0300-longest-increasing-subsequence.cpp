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

        vector<ll> hash(n+1, inf);
        ll ans = 0;
        hash[0] = -inf;

        for(int i=0; i<n; i++)
        {
            ll l,r,mid,val;
            l = 1;
            r = n;
            val = nums[i];

            while(l<=r)
            {
                mid = (l+r)/2;

                //if( (hash[mid] > val ) && (hash[mid-1]  < val ) ) break;
                if( hash[mid] >= val )
                {
                        if( hash[mid-1] < val )
                    	{
                    		break;
                    	}
                    else
                    	r = mid - 1;
                }
                else
                    l = mid + 1;
            }

            hash[mid] = val;

        }

        for(int i=0; i<=n; i++)
        {
            if(hash[i]!=inf)
            ans  = i;
        }
        return ans;
    }
};