//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int n, int k, vector<int> &a, vector<int> &b) {
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());
        
        for(int i=0; i<n; i++) pq.push({a[0] + b[i], 0});
        
        while(k--){
            int i = pq.top().first;
            int j = pq.top().second;
            pq.pop();
            ans.push_back(i);
            
            pq.push({i-a[j]+a[j+1], j+1});
        }
        
        return ans;
    }
  
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends