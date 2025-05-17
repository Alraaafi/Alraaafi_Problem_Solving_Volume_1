class Solution {
public:
    vector< vector<string> > res;

    bool isP(string st)
    {
        int i,j;

        i = 0;
        j = st.size()-1;


        bool ck = true;
        while( i<=j )
        {
            if( st[i]!=st[j] ) 
            {
                ck = false;
                break;
            }
            i++;
            j--;
        }

        return ck;
    }

    void bk( int i, string s, vector<string> p )
    {

        if( i==s.size() )
        {
            res.push_back( p );
            return ;
        }

        for(int j=i; j<s.size(); j++)
        {

            string pel = s.substr( i,  j-i+1 );


            if(isP(pel))
            {
                p.push_back( pel );
                bk( j+1, s, p );
                p.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        

        vector<string> v;
        bk( 0, s, v );
        return res;
    }
};