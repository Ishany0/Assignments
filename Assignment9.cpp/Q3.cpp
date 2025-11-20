#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

struct DSU {
    vector<int> parent, rankv;
    DSU(int n) {
        parent.resize(n);
        rankv.assign(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] == x) return x;
        parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (rankv[a] < rankv[b]) swap(a, b);
        parent[b] = a;
        if (rankv[a] == rankv[b]) rankv[a]++;
        return true;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    if (!(cin >> V >> E)) return 0;
    vector<Edge> edges(E);
    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < E; i++) cin >> edges[i].u >> edges[i].v >> edges[i].w;
    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) {
        return a.w < b.w;
    });
    DSU dsu(V);
    int mstWeight = 0;
    vector<Edge> mst;
    for (auto &e : edges) {
        if (dsu.unite(e.u, e.v)) {
            mstWeight += e.w;
            mst.push_back(e);
        }
    }
    cout << "Edges in MST:\n";
    for (auto &e : mst) cout << e.u << " " << e.v << " " << e.w << "\n";
    cout << "Total weight: " << mstWeight << "\n";
    return 0;
}
