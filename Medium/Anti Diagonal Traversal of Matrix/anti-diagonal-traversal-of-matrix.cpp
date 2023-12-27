//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
//     vector<int> antiDiagonalPattern(vector<vector<int>> matrix) 
//     {
//         int n = matrix.size();
//         vector<vector<int>> ans(n*n-1);
//         for(int i = 0;i<n;i++){
//             for(int j = 0;j<n;j++){
//                 ans[i+j].push_back(matrix[i][j]);
//             }
//         }
        
//         vector<int> answer;
//         for(auto itr:ans){
//             for(auto i:itr)
//             ans.push_back(i);
//         }
//         return answer;
//   }

vector<int> antiDiagonalPattern(vector<vector<int>> matrix) {
    int n = matrix.size();
    vector<vector<int>> ans(2 * n - 1); // Initialize the vector with the correct size

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans[i + j].push_back(matrix[i][j]);
        }
    }

    vector<int> answer;
    for (auto& itr : ans) {
        for (auto& element : itr) {
            answer.push_back(element);
        }
    }
    return answer;
}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.antiDiagonalPattern(matrix);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends