#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
bool vis[100005];

void dfs(int u) {
     vis[u] = 1;
     for (int v : adj[u]) {
          if (!vis[v]) dfs(v);
     }
}

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);

     int N, M; cin >> N >> M;
     adj.resize(N+5);
     for (int i = 1; i <= M; i++) {
          int u, v; cin >> u >> v;
          adj[u].push_back(v); adj[v].push_back(u);
     }

     vector<int> present;
     for (int i = 1; i <= N; i++) {
          if (!vis[i]) {
               present.push_back(i);
               dfs(i);
          }
     }

     cout << present.size()-1 << "\n";
     for (int i = 1; i < present.size(); i++)
          cout << present[i] << " " << present[i-1] << "\n";

     return 0;
}
