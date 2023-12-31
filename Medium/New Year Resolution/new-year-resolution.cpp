//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    
    public:
    bool help(int* coins,int i,int sum,vector<vector<int>>& memo)
    {
        if(i<0)
        {
            if(sum!=0 && (sum%20==0 || sum%24==0 || sum==2024))
            return 1;
            else
            return 0;
        }
        
        if(memo[i][sum]!=-1)
        return memo[i][sum];
        
        if(sum!=0 and (sum%20==0 || sum%24==0 || sum==2024))
        return memo[i][sum]=1;
        
        bool a=help(coins,i-1,sum,memo);
        
        if(a) return memo[i][sum]=1;
        
        bool b=help(coins,i-1,sum+coins[i],memo);
        
        return memo[i][sum]=int(b);
    }
    
    int isPossible(int N , int coins[]) 
    {
        vector<vector<int>> memo(N,vector<int>(2025,-1));
        return help(coins,N-1,0,memo);
    }
    
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int coins[N];
        for(int i=0 ; i<N ; i++)
            cin>>coins[i];

        Solution ob;
        cout << ob.isPossible(N,coins) << endl;
    }
    return 0;
}
// } Driver Code Ends