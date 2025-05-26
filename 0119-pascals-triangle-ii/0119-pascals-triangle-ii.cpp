class Solution {
    const int lim = 34;
    int dp[34][34];
    
    int slv( int r, int c )
    {
        if(c==-1 || r<c) return 0;
        if( r==0 ) return 1;

        if(~dp[r][c]) return dp[r][c];

        int ret = 0;

        ret = slv( r-1, c ) + slv( r-1, c-1 );

        return dp[r][c] = ret;
    }


public:
    vector<int> getRow(int i) {
        
        vector<int> ans;
        memset(dp, -1, sizeof(dp));
        for(int j=0; j<=i; j++)
        {
            int val = slv( i, j );

            ans.push_back(val);
        }


        return ans;
    }
};