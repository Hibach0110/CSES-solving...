#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

vector<int> adj[N];
int dp[N][2];

void dfs(int u, int p) {
     for (int v : adj[u]) {
          if (v != p) {
               dfs(v, u);
               dp[u][0] += max(dp[v][0], dp[v][1]);
          }
     }
     for (int v : adj[u]) {
          if (v != p) {
               dp[u][1] = max(dp[u][1], dp[u][0] - max(dp[v][0], dp[v][1]) + dp[v][0] + 1);
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
     cout << max(dp[1][0], dp[1][1]);     

     return 0;
}