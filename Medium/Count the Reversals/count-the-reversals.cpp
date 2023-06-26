//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string s)
{
    if(s.size()%2 == 1)return -1;
    stack<char>st;
    for(char itr:s){
        if(itr == '{'){
            st.push(itr);
        }
        else{
            if(!st.empty() && st.top() == '{'){
                st.pop();
            }
            else{
                st.push(itr);
            }
        }
    }
    int count = 0;
    while(!st.empty()){
        char a = st.top();
        st.pop();
        char b = st.top();
        st.pop();
        if(a == b)count++;
        if(a != b)count+=2;
    }
    return count;
}