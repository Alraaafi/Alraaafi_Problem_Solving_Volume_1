class Solution {
  public:
    vector<int> find(vector<int>& arr, int x) {
        int l,r,mid;
        pair<int,int> ans;
        
        l = 0;
        r = arr.size()-1;
        
        ans = {-1, -1 } ;
        
        while(l<=r)
        {
            mid = (l+r)/2;
            
            if( arr[mid] >= x )
            {
                r = mid - 1;
                if(arr[mid] == x) ans.first = mid;
            }
            else
            {
                l = mid+1;
            }
        }
        
        l = 0;
        r = arr.size()-1;
        
        while(l<=r)
        {
            mid = (l+r)/2;
            
            if( arr[mid] <= x )
            {
                l = mid+1;
                if(arr[mid] == x) ans.second = mid;
            }
            else
            {
                r = mid-1;
            }
        }
        
        
        
        return {ans.first, ans.second };
        
    }
};