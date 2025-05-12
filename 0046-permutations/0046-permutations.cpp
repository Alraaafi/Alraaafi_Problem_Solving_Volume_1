/**
         Author:  Md. Tanvir Ahmed rafi (Alraaafi)
         CF    : https://codeforces.com/profile/Alraaafi
**/


typedef long long  ll;




vector<vector<int>> res;
vector<int> tmp;
ll vis[100];
void solve( ll i, ll n, vector<int> &ar )
{
    if( tmp.size()==n )
    {
        res.push_back( tmp );
        //cout<<"TEST"<<endl;
        return ;
    }

    
    for(ll j=0; j<n; j++)
    {

        if( vis[j] ) continue;

        tmp.push_back(ar[j]);
        vis[j] = 1;
        solve( j , n, ar );
        vis[j] = 0;
        tmp.pop_back();
    }
    
}

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        memset(vis, 0, sizeof(vis));
        res.clear();
        tmp.clear();
        solve( 0, nums.size(), nums );

        return res;
    }


};