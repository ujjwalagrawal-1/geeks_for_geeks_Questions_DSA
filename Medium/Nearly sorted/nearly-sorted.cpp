//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int num, int K){
        priority_queue<int,vector<int>,greater<int>> pq;
        int t = K;
        vector<int>answer;
        for(int i = 0;i<num;i++){
           if(pq.size() <= t){
               pq.push(arr[i]);
           }
           else{
               pq.push(arr[i]);
               answer.push_back(pq.top());
               pq.pop();
           }
        }
        while(pq.size()){
            answer.push_back(pq.top());
            pq.pop();
        }
        return answer;
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    Solution ob;
	    vector <int> res = ob.nearlySorted(arr, num, K);
	    for (int i = 0; i < res.size (); i++)
	        cout << res[i] << " ";
	        
	    cout<<endl;
	}
	
	return 0;
}

// } Driver Code Ends