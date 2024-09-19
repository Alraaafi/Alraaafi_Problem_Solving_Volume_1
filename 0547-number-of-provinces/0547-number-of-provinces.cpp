#define ll long long int
ll const lim = 207;
ll pr[lim];
ll sz[lim];

ll root(ll u)
{
    if(pr[u]==u)
    return u;

    return pr[u] = root( pr[u] );
}

void uni(ll u, ll v)
{
    if(sz[u] < sz[v] )
    swap(u,v);

    pr[v] = u;
    sz[u]+=sz[v];
}

class Solution {
public:
    int findCircleNum(vector<vector<int>>& grp) {
        ll n = grp.size();
        ll i,j;

        for(i=0; i<n; i++)
        {
            pr[i] = i;
            sz[i] = 1;
        }

        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(grp[i][j]==1)
                {
                    ll u = root(i);
                    ll v = root(j);

                    if(u!=v)
                    {
                        uni( u, v );
                    }

                }
            }
        }

        ll ans = 0;

        for(i=0; i<n; i++)
        {
            if(pr[i]==i) ans++;
        }
        return ans;
    }
};