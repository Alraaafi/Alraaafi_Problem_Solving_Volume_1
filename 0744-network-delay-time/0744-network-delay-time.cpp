#define ll long long
#include<bits/stdc++.h>

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& g, ll n, int k) {
        ll src = k;
        ll lim = n;
        ll mx =  0;
        ll i;
        ll u,v,w;
        ll dist[lim+1];
        vector< pair<ll,ll> > adj[n+1];

        for(i=0; i<=n; i++) dist[i] = 1e9;

        ll sz = g.size();

        for(i=0; i<sz; i++)
        {
            u = g[i][0];
            v = g[i][1];
            w = g[i][2];

            adj[u].push_back( {v, w } );

        }

        dist[src] = 0;

        priority_queue< pair<ll,ll> , vector<pair<ll,ll>>, greater<pair<ll,ll>> > pq;

        pq.push( {0, src} ) ;

        while( !pq.empty() )
        {
            auto p = pq.top();
            u = p.second;
            ll cw = p.first;
            pq.pop();

            if( cw > dist[u] ) continue;

            for( auto pr: adj[u] )
            {
                v = pr.first;
                w = pr.second;
                if( cw+w < dist[v] )
                {
                    dist[ v ] = cw+w;
                    pq.push( { cw+w, v } );
                }
            }
        }

    ll f = 0;
    for(i=1; i<=lim; i++)
    {
         mx = max( mx, dist[i] );
         if( dist[i] == 1e9 ) f = 1;
    }


    if(f) mx = -1;





        return mx;
    }
};