#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
using ll = long long;

vector<int> adj[N];
int n;
ll dp[N], sz[N], ans[N];

void dfs(int u, int p) {
     sz[u] = 1;
     for (int v : adj[u]) {
          if (v != p) {
               dfs(v, u);
               sz[u] += sz[v];
               dp[u] += dp[v] + sz[v];
          }
     }
}

void reroot(int u, int p) {
     for (int v : adj[u]) {
          ans[u] += dp[v] + sz[v];
     }
     for (int v : adj[u]) {
          if (v != p) {
               ll dp_u = dp[u], dp_v = dp[v], sz_u = sz[u], sz_v = sz[v];
               dp[u] -= dp[v] + sz[v];
               sz[u] -= sz[v];
               dp[v] += dp[u] + sz[u];
               sz[v] = n;
               reroot(v, u);
               dp[u] = dp_u;
               dp[v] = dp_v;
               sz[u] = sz_u;
               sz[v] = sz_v;
          }
     }
}

int main() {
     ios_base::sync_with_stdio(false); cin.tie(NULL);

     cin >> n;
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