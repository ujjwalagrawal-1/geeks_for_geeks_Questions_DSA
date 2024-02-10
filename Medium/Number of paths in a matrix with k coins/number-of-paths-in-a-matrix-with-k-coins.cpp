//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
long long f(vector<vector<int>> &arr,int x,int y,int k,vector<vector<vector<int>>> &dp){
    if(x == 0 && y == 0){
        if(k == arr[x][y]){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(x<0 || y<0 || k<0){
        return 0;
    }
    if(dp[x][y][k] != -1){
        return dp[x][y][k];
    }
    
    return dp[x][y][k] = f(arr,x-1,y,k-arr[x][y],dp) + f(arr,x,y-1,k-arr[x][y],dp);
}
    long long numberOfPath(int n, int k, vector<vector<int>> arr){
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(k+1,-1)));
        return f(arr,n-1,n-1,k,dp);
        // dp[0][0][arr[0][0]] = 1;
        // for(int x = 0;x<n;x++){
        //     for(int y = 0;y<n;y++){
        //         for(int k = )
        //     }
        // }
    }
};




//{ Driver Code Starts.

int main()
{
    Solution obj;
    int i,j,k,l,m,n,t;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        vector<vector<int>> v(n, vector<int>(n, 0));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>v[i][j];
        cout << obj.numberOfPath(n, k, v) << endl;
    }
}
// } Driver Code Ends