//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int>st;
        for(int i = 0;i<n;i++){
            st.push(i);
        }
        while(st.size() != 1){
            int a = st.top();st.pop();
            int b = st.top();st.pop();
            
            if(M[a][b]){
                //a is not a celebrity(A knows B);
                st.push(b);
            }
            else{
                //b is not a celebrity(B  knows A);
                st.push(a);
            }
        }
        
        // if top element is celibtity or not 
        int migthbecelebrity = st.top();st.pop();
        for(int i = 0;i<n;i++){
            if(M[migthbecelebrity][i] != 0){
                return -1;
            }
        }
        
        for(int i = 0;i<n;i++){
            if(M[i][migthbecelebrity] == 0 && i!= migthbecelebrity){
                return -1;
            }
        }
        return migthbecelebrity;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends