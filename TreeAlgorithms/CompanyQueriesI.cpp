#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

vector<int> adj[N];
int up[N][20];

void dfs(int u, int p) {
     up[u][0] = p;
     for (int i = 1; i < 20; i++) {
          up[u][i] = up[up[u][i-1]][i-1];
     }
     for (int v : adj[u]) {
          if (v != p) dfs(v, u);
     } 
}

int main() {
     ios_base::sync_with_stdio(false); cin.tie(NULL);

     int n, q; cin >> n >> q;
     for (int i = 2; i <= n; i++) {
          int p; cin >> p;
          adj[p].push_back(i);
     }

     dfs(1, 0);     
     while (q--) {
          int u, k; cin >> u >> k;
          for (int i = 19; i >= 0; i--) {
               if (k >> i & 1) {
                    u = up[u][i];
               }
          }
          cout << (u == 0 ? -1 : u) << "\n";
     }

     return 0;
}