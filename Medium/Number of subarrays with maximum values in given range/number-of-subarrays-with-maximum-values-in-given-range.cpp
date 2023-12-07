//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    long countSubarrays(int a[], int n, int L, int R)
    {
        long range = 0; 
        long ans = 0; 
        long j = 0;
        for(long i = 0;i<n;i++){
            if(a[i]>=L && a[i]<=R){
                range = i-j+1;
            }
            else if(a[i] > R){
                range = 0;
                j = i+1;
            }
            
            ans += range;
        }
        return ans;
    }
};

//{ Driver Code Starts.
// driver program
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        
        int n ,l,r;
        cin >> n>>l>>r;
        int a[n];
        for(int i=0;i<n;i++)
        cin >> a[i];
        Solution ob;
    	cout << ob.countSubarrays(a, n, l, r)<<endl;
    }
	return 0;
}

// } Driver Code Ends