#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
    Edge(int _u, int _v, int _w) {
        u = _u;
        v = _v;
        w = _w;
    }
};

int n, m;
int parent[1000], sz[1000];
vector<Edge> edges;

void make_set() {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
}

int Find(int v) {
    if (v == parent[v]) return v;
    return parent[v] = Find(parent[v]);
}

bool Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a == b) return false;
    if (sz[a] < sz[b]) swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
    return true;
}

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        edges.push_back(Edge(x, y, w));
    }
}

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

void kruskal() {
    vector<Edge> mst;
    int d = 0;

    sort(edges.begin(), edges.end(), cmp);

    for (int i = 0; i < m; i++) {
        if ((int)mst.size() == n - 1) break;
        Edge c = edges[i];
        if (Union(c.u, c.v)) {
            mst.push_back(c);
            d += c.w;
        }
    }

    cout << d << endl;
    for (auto x : mst) cout << x.u << " " << x.v << " " << x.w << "\n";
}

int main() {
    input();
    make_set();
    kruskal();
}
