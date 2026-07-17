#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int timer = 0;
vector<int> adj[N];
int tin[N], tout[N], up[N][20], h[N];

void dfs(int u, int p) {
     tin[u] = timer++;
     up[u][0] = p;
     for (int i = 1; i < 20; i++) {
          up[u][i] = up[up[u][i-1]][i-1];
     }
     for (int v : adj[u]) {
          if (v != p) {
               h[v] = h[u] + 1;
               dfs(v, u);
          }
     }
     tout[u] = timer++;
}

bool is_ancestor(int u, int v) {
     return tin[u] <= tin[v] && tout[v] <= tout[u];
}

int get_lca(int u, int v) {
     if (is_ancestor(u, v)) return u;
     if (is_ancestor(v, u)) return v;
     for (int i = 19; i >= 0; i--) {
          if (!is_ancestor(up[u][i], v)) u = up[u][i];
     }
     return up[u][0];
}

int ans[N], a[N];

void doit(int u, int p) {
     ans[u] = a[u];
     for (int v : adj[u]) {
          if (v != p) {
               doit(v, u);
               ans[u] += ans[v];
          }
     }
}

int main() {
     ios_base::sync_with_stdio(false); cin.tie(NULL);

     int n, q; cin >> n >> q;
     for (int i = 1; i < n; i++) {
          int u, v; cin >> u >> v;
          adj[u].push_back(v);
          adj[v].push_back(u);
     }
     dfs(1, 1);
     while (q--) {
          int u, v; cin >> u >> v;
          int diff_node;
          if (is_ancestor(u, v)) {
               diff_node = (u == 1 ? 0 : up[u][0]);
               a[v]++;
          } else if (is_ancestor(v, u)) {
               diff_node = (v == 1 ? 0 : up[v][0]);
               a[u]++;
          } else {
               int cl = u;
               for (int i = 19; i >= 0; i--) {
                    if (!is_ancestor(up[cl][i], v)) cl = up[cl][i];
               }
               cl = up[cl][0];
               diff_node = (cl == 1 ? 0 : up[cl][0]);
               a[u]++;
               a[v]++;
               a[cl]--;
          }
          a[diff_node]--;
     }

     doit(1, 1);

     for (int i = 1; i <= n; i++) {
          cout << ans[i] << " ";
     }

     return 0;
}