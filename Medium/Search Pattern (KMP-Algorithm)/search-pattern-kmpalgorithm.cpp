//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        // bool check(string &txt, string &pat, int ind){
        //     int n = pat.length();
        //     for(int i=0; i<n; i++)
        //         if(pat[i] != txt[ind+i])
        //             return false;
        //     return true;
        // }
    
        vector <int> search(string pat, string txt)
        {
            vector<int> ans;
            if(pat.length() > pat.length()) return ans;
            int n = txt.length();
            
            function<bool(const string&, const string&, int)> check = [&](const string &txt,const string &pat, int ind) -> bool{
                int n = pat.length();
                for(int i=0; i<n; i++)
                if(pat[i] != txt[ind+i])
                    return false;
                return true;
            };
        
            for(int i=0; i<n; i++){
                if(check(txt, pat, i)){
                    ans.push_back(i+1);
                }
            }
            return ans;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends