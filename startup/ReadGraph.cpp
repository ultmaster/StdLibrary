#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct Edge {
    int from, to, cost;
};

const int N = 1e5 + 10;
int n, m;
vector<Edge> edges;
vector<int> g[N];

void add_edge(int x, int y, int z) {
    edges.push_back((Edge){x, y, z});
    edges.push_back((Edge){y, x, z});
    int M = edges.size();
    g[x].push_back(M - 2);
    g[y].push_back(M - 1);
}

int main() {
    while (~scanf("%d%d", &n, &m)) {
        edges.clear();
        for (int i = 1; i <= n; ++i)
            g[i].clear();
        for (int i = 0; i < m; ++i) {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            add_edge(x, y, z);
        }
    }
    return 0;
}
