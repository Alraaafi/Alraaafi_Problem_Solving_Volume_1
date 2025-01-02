class Solution {
public:
    int countPrimes(int n) {

        if(n==0) return 0;
        int isp[n+1];
        memset(isp, 0 , sizeof(isp) );
        vector<int> p;

        int i,j;
        isp[0] = 1;
        isp[1] = 1;


        int cnt = 0;

        for(i=2; i*i<n; i++)
        {
            if( isp[i]==0 )
            {
                //cnt++;
                for(j=i*i; j<n; j=i+j)
                isp[j] = 1;
            }
        }

        for(i=1; i<n; i++) 
        if(isp[i]==0) cnt++;
        

        return cnt;
    }
};