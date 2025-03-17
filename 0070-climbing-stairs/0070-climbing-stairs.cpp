#include<bits/stdc++.h>
int step1( int i, int n , vector<int> &dp)
{
    if( i==n ) return 1;

    if( dp[i] != -1 ) return dp[i];

    int ans = 0;

    ans+= ( step1( i+1 , n , dp) );

    if( i+2 <= n )
        ans+= ( step1( i+2 , n, dp ) );
    return dp[i] = ans;
}

class Solution {
public:
    int climbStairs(int n) {

        vector<int> dp( n+1,-1 );
        return step1(0, n, dp);
    }
};