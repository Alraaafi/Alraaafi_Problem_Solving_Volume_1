
bool chk(map<char,int> &s, map<char,int> &p )
{
    for(auto m: s)
    {
        if( m.second != p[ m.first ] )
        return false;
    }


    return true;
}


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        int sn,pn;
        sn = s.size();
        pn = p.size();
        int i,j;
        vector<int> ans;

        map<char,int> pat,str;
        queue<char> q;

        for(i=0; i<pn; i++)
        {
            pat[ p[i] ]++;
        }


        if( sn<pn )
        {
            return ans;
        }

        for(i=0; i<pn; i++)
        {
            str[ s[i] ]++;
            q.push( s[i] );
        }

        bool ck = chk( str,pat );

        if(ck) ans.push_back( 0 );

        j = 1;

        for(i=pn; i<sn; i++)
        {
            char pre,post;
            post = s[i];
            pre = q.front();
            q.pop();
            q.push(post);

            str[ pre ] --;
            str[ post ] ++;

            if( chk( str, pat ) )
                ans.push_back( j );




            j++;
        }





        return ans;
    }
};