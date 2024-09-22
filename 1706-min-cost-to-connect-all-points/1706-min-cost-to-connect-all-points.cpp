#define ll long long

ll const lim = 1007;
ll per[lim];
ll cost[lim];



ll dist( ll x1, ll x2, ll y1, ll y2 )
{
    ll d = abs(x1-x2) + abs(y1-y2) ; //|xi - xj| + |yi - yj|
    return d;
}

ll rep( ll u )
{
    if(per[u]==u)
    return u;
    
    return per[u] = rep( per[u] );
}

void uni(ll u, ll v )
{
    if( cost[u] < cost[v] )
    swap(u,v);

    per[v] = u;
    cost[u]+=cost[v];
}

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& v) {

        vector< pair<ll, pair<ll,ll> > > p;
        ll n = v.size();

        ll i,j;

        for(i=0; i<n; i++)
        {
           per[i] = i;
           cost[i] = 1;
        }
        

        for(i=0; i<n; i++)
        {
            for(j=i+1; j<n; j++)
            {
                ll x1,x2,y1,y2,d;

                x1 = v[i][0];
                y1 = v[i][1];

                x2 = v[j][0];
                y2 = v[j][1];

                d = dist( x1,x2,y1,y2 );
                
                p.push_back( { d, {i,j} } );

            }
        }

        sort(p.begin(), p.end() );
        ll m = p.size();


        ll cnt = 0,res=0;
        for(i=0 ;i<m; i++)
        {
            ll u, v, w;

            w = p[i].first;
            auto pr = p[i].second;
            ll v1 = pr.first;
            ll u1 = pr.second;

            v = rep(v1);
            u = rep(u1);

            if(v!=u)
            {
                cnt++;
                res+=w;
                uni(u,v);
            }
            
            if(cnt == n-1)
                break;
        }


    return res;
    }
};