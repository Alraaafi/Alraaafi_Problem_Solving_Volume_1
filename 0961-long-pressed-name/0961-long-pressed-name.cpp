class Solution {
public:
    bool isLongPressedName(string &a, string &t) {
        int n = a.size();
        int m = t.size();

        int i,j;

        bool f = true;

        i = 0;
        j = 0;

        char ch,c2;
        for( ;i<n && j<m ; )
        {
            if( a[i]==t[j])
            {
                ch = t[j];
                c2 = a[i];
                i++;
                j++;
                
            }
            else
            {
                ch = t[j];
                j++;
                if( c2!=ch )
                    return false;
                

                //if( j>0 && t[j-1] j )
            }
        }

        //cout<<i<<" "<<j<<" "<<ch<<" "<<t[j]<<endl;
        for( ;j<m; j++ )
        {
            if( t[j]!= ch ){
                return false;
            }
            ch = t[j];
        }

        

        if( i==n && j==m ) f = true;
        else f = false;

        return f;
    }
};