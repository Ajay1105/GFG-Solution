//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int kSubstrConcat (int n, string s, int k)
	{
	    if(n%k) return 0;
	    
	    string s1,s2;
	    int c1=1, c2=0, i;
	    s1=s.substr(0,k);
	    
	    for(i=k; i<n; i+=k){
	        string temp = s.substr(i,k);
	        if(s1==temp) c1++;
	        else{
	            s2=temp;
	            c2++;
	            break;
	        }
	    }
	    
	    for(i+=k; i<n; i+=k){
	        string temp = s.substr(i,k);
	        if(temp != s1 && temp != s2) return 0;
	        if(temp == s1) c1++;
	        else if(temp==s2)c2++;
	    }
	    
	    if(c1==0 || c2==0) return 1;
	    if(c1==1 || c2==1) return 1;
	    return 0;
	}
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		int k; cin >> k;
        Solution  ob;
		cout << ob.kSubstrConcat (n, s, k) << endl;
	}
}
// } Driver Code Ends