#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
vector<int> adj[N];
int sz[N];

void dfs(int u, int p) {
     sz[u] = 1;
     for (int v : adj[u]) {
          if (v != p) {
               dfs(v, u);
               sz[u] += sz[v];
          }
     }
}

int find_centroid(int u, int p, int n) {
     int max_v_size = 0, v_branch;
     for (int v : adj[u]) {
          if (v != p) {
               if (max_v_size < sz[v]) {
                    max_v_size = sz[v];
                    v_branch = v;
               }
          }
     }
     return (max_v_size <= n / 2 ? u : find_centroid(v_branch, u, n));
}

int main() {
     ios_base::sync_with_stdio(false); cin.tie(NULL);

     int n; cin >> n;
     for (int i = 1; i < n; i++) {
          int u, v; cin >> u >> v;
          adj[u].push_back(v);
          adj[v].push_back(u);
     }

     dfs(1, 1);
     cout << find_centroid(1, 1, n);

     return 0;
}