//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    
    bool areRotations(std::string s1, std::string s2)
{
    if (s1.length() != s2.length()) {
        return false;
    }

    queue<char> q1;
    queue<char> q2;

    for (char itr : s1) {
        q1.push(itr);
    }
    for (char itr : s2) {
        q2.push(itr);
    }

    // Check for rotations
    for (int i = 0; i < s1.size(); i++) {
        
        if (q1 == q2) {
            return true;
        }

      
        char ch = q1.front();
        q1.pop();
        q1.push(ch);
    }

    return false;
}
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        Solution obj;
        cout<<obj.areRotations(s1,s2)<<endl;

    }
    return 0;
}

// } Driver Code Ends