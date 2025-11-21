#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, start;
    cin >> n >> m >> start;

    vector<vector<pair<int,int>>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    vector<int> dist(n, INT_MAX);
    dist[start] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int du = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (du != dist[u]) continue;

        for (auto &p : g[u]) {
            int v = p.first, w = p.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    for (int d : dist) cout << d << " ";
}
