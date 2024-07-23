//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  bool bfs(int vis[],vector<int> adj[],int n){
      queue<pair<int,int>> qu;
      qu.push({n,-1});
      vis[n] = 1;
      while(!qu.empty()){
          int node = qu.front().first;
          int parent = qu.front().second;
          qu.pop();
          
          for(auto adjacentnode : adj[node]){
              if(!vis[adjacentnode]){
                  qu.push({adjacentnode,node});
                  vis[adjacentnode] = 1;
              }
              else if(parent != adjacentnode){
                  return true;
              }
          }
      }
      return false;
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int vis[V] = {0};
        for(int i = 0;i<V;i++){
            if(!vis[i]){
                if(bfs(vis,adj,i) == true){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends