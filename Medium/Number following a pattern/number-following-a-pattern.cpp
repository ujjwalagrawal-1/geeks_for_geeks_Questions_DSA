//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    // string printMinNumberForPattern(string S){
    //     string ans = "";
    //     int i = 0;
    //     if(S[0] == 'D'){
    //         // first find the First D char in the strings 
    //         int x = 0;
    //         int j = 0;
    //         while(true){
    //             if(S[j] != 'D'){
    //                 break;
    //             }
    //             else{
    //                 x++;j++;
    //             }
    //         }
    //         x++;
    //         while(x != 1){
    //             S.push_back('x');
    //             x--;
    //         }
            
    //     }
    //     else{
            
    //     }
    
    string printMinNumberForPattern(string S){
        vector<pair<char, int>> col;
        char curr = S[0];
        int c = (S[0] == 'I');
        
        for (auto i: S){
            if (i == curr)
                ++c;
            else{
                col.push_back({curr, c});
                c = 1;
                curr = i;
            }
        }               
        if (S.back() == 'I')
            ++c;
        col.push_back({curr, c});
        
        string out;
        c = 1;
        for (auto i: col){
            char op = i.first;
            int cnt = i.second + (op == 'D'? 1: -1);
            string temp;
            while (cnt--){
                temp += (char)('0' + c++);
            }
            if (op == 'D')
                reverse(temp.begin(), temp.end());
            out += temp;
        }
        return out;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 

// } Driver Code Ends