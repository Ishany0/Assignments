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
    }
    int src;
    cout << "Enter source vertex: ";
    cin >> src;
    const int INF = 1e9;
    vector<int> dist(V, INF);
    dist[src] = 0;
    using P = pair<int,int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, src});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dist[u]) continue;
        for (auto &e : adj[u]) {
            int v = e.v, w = e.w;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    cout << "Shortest distances from source:\n";
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF) cout << i << ": INF\n";
        else cout << i << ": " << dist[i] << "\n";
    }
    return 0;
}
