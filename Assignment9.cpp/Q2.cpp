#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<vector<int>> &adj, vector<bool> &vis) {
    vis[u] = true;
    cout << u << " ";
    for (int v : adj[u]) if (!vis[v]) dfs(v, adj, vis);
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    if (!(cin >> V >> E)) return 0;
    vector<vector<int>> adj(V);
    cout << "Enter edges (u v) 0-based:\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int src;
    cout << "Enter source vertex: ";
    cin >> src;
    vector<bool> vis(V, false);
    cout << "DFS traversal: ";
    dfs(src, adj, vis);
    cout << "\n";
    return 0;
}
