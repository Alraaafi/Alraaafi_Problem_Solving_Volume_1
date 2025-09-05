class Solution {
public:
    int maxScore(vector<int>& v, int k) {
        int n = v.size();
        int m = n - k;


        int s = 0;

        for(auto a: v) s+=a;

        queue<int> q;

        int i,j;


        int sp = 0;
        for( i=0; i<m; i++ )
        {
            q.push( v[i] );
            sp+=v[i];
        }

        int mn = sp;

        for(i=m; i<n; i++)
        {
            if(m==0) break;
            int pre,post;
            pre = q.front();
            post = v[i];

            q.pop();
            q.push(post);

            
            sp= sp + post;
            sp= sp - pre;

           // cout<<sp<<" "<<i<<endl;

            mn = min( mn, sp );



        }



        return  s-mn;
    }
};