class Solution {
public:
    void moveZeroes(vector<int>& nm) {
        int l=0,r=0;

        for(r=0; r<nm.size(); r++)
        {
            swap( nm[r], nm[l] );
            if( nm[l] ) l++;
        }


        for(auto v: nm) cout<<v<<" "; cout<<endl;
    }
};