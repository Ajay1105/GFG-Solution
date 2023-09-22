//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:

int solve(int nums[] , int l , int r, int target)
{
    int ans = -1;
    while(r >= l){
        int mid = (l+r)/2;
        if(nums[mid] == target)
        {
            return mid;
        }else{
            if(nums[mid] < target){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
    }
    return ans;
}


vector<int> find(int nums[], int n , int target )
{
        //finding any position  of target value 
        int index = solve(nums , 0 , n-1 , target);
        int l =index , r = index;
        //now solve separately
        while(1){
            int left = solve(nums,0,l-1,target);
            int right = solve(nums,r+1,n-1,target);
            if(left == -1 && right == -1){
                break;
            }
            if(left != -1){
                l = left;//updating the index that we get from the left side of the index .
            }

            if(right  != -1){
                r = right;//updating the index that we get from the right side of the index
            }
        }
        return {l , r}; 
   
}
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends