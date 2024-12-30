#define ll long long
ll const lim  = 1e3 + 5;
ll dp[lim][lim];
ll n1,n2;
string s1,s2;

ll slv( ll i , ll j )
{
    if( i>=n1 || j>=n2 ) return 0;
    if( dp[i][j]!=-1 ) return dp[i][j];

    ll res = 0;

    if( s1[i]==s2[j] )
    {
        res = 1+slv( i+1, j+1 );
    }
    else
    {
        res = max( slv(i+1, j), slv(i, j+1) );
    }

    return dp[i][j] = res;
}


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        ll ans;
        s1 = text1;
        s2 = text2;
        n1 = s1.size();
        n2 = s2.size();

        memset(dp, -1, sizeof(dp));

        ans = slv(0,0);



        return ans;
    }
};