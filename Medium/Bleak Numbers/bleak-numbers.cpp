//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
	int is_bleak(int n)
	{
        function<int(int)> countSetBits = [](int n){
            int temp = 1, count = 0;
            while(temp <= n){
                if(n&temp)count++;
                temp <<= 1;
            }
            return count;
        };
        
        for(int i=max(n-32,1); i<n; i++)
	        if(i+countSetBits(i)==n) return 0;
	    return 1;
	}
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    }
	return 0;
}

// } Driver Code Ends