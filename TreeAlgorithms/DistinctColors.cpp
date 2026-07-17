#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
vector<int> adj[N];
set<int> sz[N];
int color[N], ans[N];

void dfs(int u, int p) {
     sz[u].insert(color[u]);
     for (int v : adj[u]) {
          if (v != p) {
               dfs(v, u);
               if (sz[v].size() > sz[u].size()) {
                    swap(sz[u], sz[v]);
               }
               for (int col : sz[v]) sz[u].insert(col);
          }    
     }
     ans[u] = sz[u].size();
}

int main() {
     ios_base::sync_with_stdio(false); cin.tie(NULL);

     int n; cin >> n;
     for (int i = 1; i <= n; i++) {
          cin >> color[i];
     }
     for (int i = 1; i < n; i++) {
          int u, v; cin >> u >> v;
          adj[u].push_back(v);
          adj[v].push_back(u);
     }

     dfs(1, 1);
     for (int i = 1; i <= n; i++) {
          cout << ans[i] << " ";
     }

     return 0;
}