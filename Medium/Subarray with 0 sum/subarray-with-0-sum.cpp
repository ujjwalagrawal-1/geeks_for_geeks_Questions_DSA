//{ Driver Code Starts
// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
    public:
    // X
   #include <unordered_map>

    bool subArrayExists(int arr[], int n) {
        int sum = 0;
        unordered_map<int, bool> m;
        m[0] = true;
    
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (m.find(sum) != m.end())
                return true;
            m[sum] = true;
        }
    
        return false;
    }

};

//{ Driver Code Starts.
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    Solution obj;
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}
// } Driver Code Ends