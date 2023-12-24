//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        vector<pair<int,int>> vec;
        int ans = 0;
        
        for(int i=0; i<n; i++)
            vec.push_back({i+1, price[i]});
        
        sort(vec.begin(), vec.end(), [&](const pair<int,int> a, const pair<int,int> b){
            return a.second < b.second;
        });
        
        for(auto i:vec){
            if(k<i.second) break;
            int temp = min(i.first, k/i.second);
            ans += temp;
            k-=(temp*i.second);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends