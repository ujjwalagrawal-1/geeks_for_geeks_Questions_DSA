//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void sort012(vector<int>& veci) {
        // code here
        int i = 0,j = 0,k = veci.size()-1;
        while(j <= k){
            if(veci[j] == 0){
                swap(veci[i],veci[j]);
                i++;
                j++;
            }
            else if(veci[j] == 1){
                j++;
            }
            else{
                swap(veci[j],veci[k]);
                k--;
            }
        }
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> a;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}

// } Driver Code Ends