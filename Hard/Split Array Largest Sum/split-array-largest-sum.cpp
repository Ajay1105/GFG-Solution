//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int splitArray(int arr[] ,int N, int K) {
        int sum = 0;
        for(int i=0; i<N; i++) sum += arr[i];
        int h=sum, l=0, m, ans=-1;
        
        while(h>=l){
            m = l + (h-l)/2;
           // cout << h<< " " << l << " " << m<<endl;
            
            int tempK = K, curr = 0, i=0;
            
            for(; i<N; i++){
                if(!tempK) break;
                curr += arr[i];
                if(curr > m){
                    i--;
                    curr = 0;
                    tempK--;
                }
            }
            
            if(i==N && tempK>=1){
                ans = m;
                h=m-1;
            }
            else l=m+1;
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
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends