//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
int Lower_Bound(vector<int>& veci,int m,int target){
    int s = 0;
    int e = m-1;
    int ans = -1;
    while(s <= e){
        int mid =  s + (e - s)/2;
        if(veci[mid] >= target){
            ans = mid;
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }
    return ans;
}
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int ans = 0;
	    int ones = -1;
	    for(int i = 0;i<n;i++){
	        vector<int> veci = arr[i];
	        int val = Lower_Bound(veci,m,1);
	        int c = m - (val >= 0 ? val : m);
	       // ans = max(c,ans);
	        if(c  > ans){
	            ans = c;
	            ones = i;
	        }
	    }
	    return ones;
	}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends