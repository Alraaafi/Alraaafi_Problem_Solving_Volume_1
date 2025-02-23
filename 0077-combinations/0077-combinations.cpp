typedef long long  ll;
class Solution {

ll n,k;
vector< vector<int> > ans;
vector<int> com;

void solve(ll i, ll j)
{
   
    if( com.size()==k )
    {
        ans.push_back(com);
        return ;
    }

        for(ll p = i; p<=n; p++ )
        {
            com.push_back(p); 
            solve( p+1 , j+1 );
            com.pop_back(); 
        }

}
    
public:
    vector<vector<int>> combine(int nn, int kk) {

        n = nn;
        k = kk;
        solve(1, 0);
        return ans;
    }
};