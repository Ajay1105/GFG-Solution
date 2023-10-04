//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &s) {
        int n = s.length();
        int high = 0, ans = 0;
        unordered_map<char,int> mp;
        
        reverse(s.begin(), s.end());
        mp['I'] = 1; mp['V'] = 5; mp['X'] = 10; mp['L'] = 50; mp['C'] = 100; mp['D'] = 500; mp['M'] = 1000;
        
        for(int i=0; i<n; i++){
            int value = mp[s[i]];
            if(value < high) ans -= value;
            else{
                ans += value;
                high = value;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends