#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

vector<int> adj[N];
int ans[N], max_dist[N];

void dfs(int u, int p) {
     for (int v : adj[u]) {
          if (v != p) {
               dfs(v, u);
               max_dist[u] = max(max_dist[u], max_dist[v] + 1);
          }
     }
}

void reroot(int u, int p) {
     int fi_dist = 0, se_dist = 0;
     for (int v : adj[u]) {
          if (fi_dist < max_dist[v] + 1) {
               se_dist = fi_dist;
               fi_dist = max_dist[v] + 1;
          } else if (se_dist < max_dist[v] + 1) {
               se_dist = max_dist[v] + 1;
          }
     }
     ans[u] = fi_dist;
     for (int v : adj[u]) {
          if (v != p) {
               int tmp = max_dist[u];
               max_dist[u] = (max_dist[v] + 1 == fi_dist ? se_dist : fi_dist);
               reroot(v, u);
               max_dist[u] = tmp;
          }
     }
}

int main() {
     ios_base::sync_with_stdio(false); cin.tie(NULL);

     int n; cin >> n;
     for (int i = 1; i < n; i++) {
          int u, v; cin >> u >> v;
          adj[u].push_back(v);
          adj[v].push_back(u);
     }

     dfs(1, 0);
     reroot(1, 0);
     for (int i = 1; i <= n; i++) {
          cout << ans[i] << " ";
     }

     return 0;
}