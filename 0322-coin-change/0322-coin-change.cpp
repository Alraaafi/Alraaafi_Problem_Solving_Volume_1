class Solution {

int solve( int a, vector<int> &c, vector<int> &dp)
{
    if(a==0) return 0;
    if(dp[a] != -1) return dp[a];
    int ans = INT_MAX;

    for(auto &con: c)
    {
        if( a-con >=0 ) ans = min( ans+0LL, solve(a-con, c, dp) + 1*1LL );
    }

    return dp[a] = ans;
}
public:
    int coinChange(vector<int> &c, int am) {
        vector<int> dp(am+2, -1);

        
        int ans = solve( am, c, dp  );

        return ans==INT_MAX  ? -1 : ans;
        
    }
};