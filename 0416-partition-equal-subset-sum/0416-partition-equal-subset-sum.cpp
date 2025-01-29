class Solution {

    int solve(int s,int i, vector<int> &n, vector<vector<int>> &dp)
    {
        if(s<0 || i>=n.size()) return s==0;

        if(dp[s][i] != -1) return dp[s][i];

        int ck = 0;

        ck = max( ck, solve(s-n[i], i+1, n, dp) );
        ck = max( ck, solve(s, i+1, n,dp) );
        

        return dp[s][i] = ck;
    }
public:
    bool canPartition(vector<int>& nums) {
        int s =  0;
        for(auto n: nums)
        {
            s+=n;
        }
        if(s%2) return false;

        vector< vector<int> > dp;

        for(int i=0; i<=s/2+3; i++)
        {   //dp.push_back({-1});
            vector<int> v;
            for(int j=0; j<=nums.size()+3; j++)
            {
                v.push_back( -1 );
            }
            dp.push_back(v);
        }

        int ck = solve( s/2,0, nums, dp );
        return ck==1;
    }
};