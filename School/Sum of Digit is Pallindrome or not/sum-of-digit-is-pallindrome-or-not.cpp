//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int isDigitSumPalindrome(int n) {
        // code here
        int s=0;
        while(n)
        {
            s = s + (n%10);
            n = n /10;
        }
        
        string sr,str = to_string(s);
        sr  =  str;
        reverse(str.begin(),str.end());
        
        if(sr==str)
        return 1;
        else
        return 0;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isDigitSumPalindrome(N) << "\n";
    }
}

// } Driver Code Ends