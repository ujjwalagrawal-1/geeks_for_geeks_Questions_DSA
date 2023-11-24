//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// #define ll long long
class Solution{
public:
    vector<long long> nthRowOfPascalTriangle(int n) {
        if(n == 1){
            return {1};
        }
        if(n == 2){
            return {1,1};
        }
        
        vector<long long> prev = nthRowOfPascalTriangle(n-1);
        
        vector<long long> ans(n);
        ans[0] = ans[n-1] = 1;
        for(int i = 1;i<n-1;i++){
            ans[i] = prev[i-1]+prev[i];
            ans[i] %= 1000000007;
        }
        return ans;
    }
};


//{ Driver Code Starts.


void printAns(vector<long long> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Endshttps://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gifhttps://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif