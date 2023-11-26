//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> pattern(int N){
        int si = N%5 ==0 ? (N/5)*2 + 1 : (N/5)*2 + 3;
        if(N < 0)
        return {N};
        vector<int> ans(si);
        int y = N;
        int i = 0,j = si-1;
        while(i<=j){
            ans[i] = ans[j] = y;
            i++;j--;
            y -= 5;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends