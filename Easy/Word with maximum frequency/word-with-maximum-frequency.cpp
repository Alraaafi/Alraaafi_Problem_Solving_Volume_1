//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



string maximumFrequency(string s);

int main()
{
    int t;cin>>t;
    cin.ignore();

    for(int i=0;i<t;i++)
    {

        string s;
        getline(cin,s);
        
        
        cout << maximumFrequency(s) << endl;

    }
    return 0;
}

// } Driver Code Ends


string maximumFrequency(string s){
    
    vector<string> vs;
    string tmp;
    
    for(auto &ch: s)
    {
        if(ch==' ') 
        {
            vs.push_back(tmp);
            tmp.clear();
        }
        else
        
          tmp+=ch;
    }
    vs.push_back(tmp);
    
    int max=1;
    string str;
    map<string,int> mp;
    
    for(auto v: vs)
    {
        mp[v]++;
    }
    
    for(auto vv: vs)
    {
        if(max<mp[vv])
        {
             max = mp[vv];
             str = vv;
             
        }
    }
    
    if(max==1)
     str = vs[0];
     
    str = str + " ";
    // str.push_back(" ");
    
    str = str + to_string(max);
    return str;
   //cout<<str<<" "<<max<<endl;
    
    
}

