#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int v, w;
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    if (!(cin >> V >> E)) return 0;
    vector<vector<Edge>> adj(V);
    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int src = 0;
    vector<int> key(V, INT_MAX), parent(V, -1);
    vector<bool> inMST(V, false);
    key[src] = 0;
    using P = pair<int,int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, src});
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (inMST[u]) continue;
        inMST[u] = true;
        for (auto &e : adj[u]) {
            int v = e.v, w = e.w;
            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }
    int total = 0;
    cout << "Edges in MST:\n";
    for (int v = 1; v < V; v++) {
        if (parent[v] != -1) {
            cout << parent[v] << " " << v << " " << key[v] << "\n";
            total += key[v];
        }
    }
    cout << "Total weight: " << total << "\n";
    return 0;
}
