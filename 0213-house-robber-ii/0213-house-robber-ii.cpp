


#define ll long long
ll n;
ll dp[103][3];

ll solve(ll i, ll f, vector<int> &a)
{
    if( i>=n )
    {
        return 0;
    }

    if(~dp[i][f]) return dp[i][f];

    ll ret = 0;

    if(i==0)
        ret = a[i] + solve(i+2, 1, a);
    else if( (i==n-1 && f==1) == 0 ) ret = a[i] + solve(i+2, f, a);

    if( (i+1<n-1) )
        ret = max( ret, a[i+1] + solve(i+3, f, a) );
    if( i+1==n-1 && f==0 )
        ret = max( ret, a[i+1] + solve(i+3, f, a) );

    if( (i+2<n-1) )
        ret = max( ret, a[i+2] + solve(i+4, f, a) );
    if( i+2==n-1 && f==0 )
        ret = max( ret, a[i+2] + solve(i+4, f, a) );

    return dp[i][f] = ret;
}
class Solution {
public:
    int rob(vector<int> &a) {
        n = a.size();
        memset(dp,-1, sizeof(dp));
        ll ans = solve(0,0,a);
        




        return ans;
    }
};