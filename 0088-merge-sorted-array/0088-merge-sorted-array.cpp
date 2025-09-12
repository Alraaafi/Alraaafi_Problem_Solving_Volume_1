class Solution {
public:
    void merge(vector<int>& n1, int n, vector<int>& n2, int m) {
        
        vector<int> ans(n+m);

        int i,j,k;
        i = 0;
        j = 0;
        k = 0;


        while( j<m && i<n )
        {
            //if( n1[i]==0 && (n-i-1)==m )
                //break;
            if( n1[i] >= n2[j] ) ans[k++] = n2[j++];
            else ans[k++] = n1[i++];
        }

        for( ;i<n  ; i++) ans[k++] = n1[i];
        for( ;j<m; j++) ans[k++] = n2[j];

        for(i=0; i<n+m; i++)
        {
            n1[i] = ans[i];
        }




    }
};